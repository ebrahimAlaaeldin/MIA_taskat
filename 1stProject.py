from playerclass import villainPlayer
from playerclass import GruWeapon
from playerclass import GruShields
from playerclass import VectorWeapon
from playerclass import VectorShields
import random

# Create a villainPlayer object
gru = villainPlayer("Gru",100,500)
Vect= villainPlayer("Vector",100,500)

# Create a GruWeapon object
FG = GruWeapon("Freeze Gun",50,11,0,-1)  # 50 energy, 11 damage, 0 avoidence
EP = GruWeapon("Electric Prod",88,15,0,5)  # 25 energy, 6 damage, 0 avoidence
MM= GruWeapon("Mega Magnet",100,20,0,0.2,3)  # 100 energy, 20 damage, 0 avoidence, 20% nextDamage
KM=GruWeapon("Kalman Missile",120,20,100,0,1)  # 120 energy, 20 damage, 100 avoidence, 0% nextDamage
# Create a GruShields object
EPB=GruShields("Energy Prohected BarrierGun",20,0.4,-1)  # 20 energy, 40% save
SP=GruShields("Selective Permeability",50,0.9,2)  # 50 energy, 60% save
# Create a VectorWeapon object
LB=VectorWeapon("Laser Blaster",40,8,-1)  # 50 energy, 11 damage
PG=VectorWeapon("Plasma Grenades",56,12,8)  # 25 energy, 6 damage
SRC=VectorWeapon("Sonic Resonance Cannon",100,22,3)  # 100 energy, 20 damage
# Create a VectorShields object
ENT=VectorShields("Energy Nullification Field",15,0.32)  # 15 energy, 32% save
QD=VectorShields("Quantum Deflector",40,0.8)  # 80 energy, 80% save
## game loop
print("                       Welcome to the game of Villains! ")
print("                       --------------------------------")
print("                       Gru vs Vector")
print("                       --------------------------------")
print("  Gru's weabon    Gru's shield ")
print("  1.Freeze Gun (FG)   1.Energy Prohected BarrierGun (EPB)")
print("  2.Electric Prod (EP) 2.Selective Permeability (SP) ")
print("  3.Mega Magnet (MM) ")
print("  4.Kalman Missile (KM) ")
print("  Vector's weabon Vector's shield ")
print("  1.Laser Blaster (LB) 1.Energy Nullification Field (ENT) ")
print("  2.Plasma Grenades (PG) 2.Quantum Deflector (QD) ")
print("  3.Sonic Resonance Cannon (SRC) ")
print("                  please choose the object using suffix \n\n    ")
print("                       Start Game                                            ")
print("                  --------------------")
print("Gru's Health =100     Gru's Energy =500             Vector's Health = 100   Vector's Energy = 500   ")
bol=True
NextDamage=0

while(bol):
   
    vectorShield=random.choice([ENT,QD])
    ## Gru's turn and Vector's turn to defend himself
    if(vectorShield==QD and QD.resource==0):
        vectorShield=ENT
    else:
        QD.resource-=1       
    gruWeapon=input("Gru's Weapon: ")
    while(True):
        if(gruWeapon=="FG" ):
            Vect.reduceHealth(FG.damage*(1-vectorShield.save))
            gru.reduceEnergy(FG.energy)
            break
           
        elif (gruWeapon=="EP" and EP.resource !=0):
            Vect.reduceHealth(EP.damage*(1-vectorShield.save))
            gru.reduceEnergy(EP.energy)
            EP.resource-=1
            break
         
        elif(gruWeapon=="MM" and MM.resource !=0): # 20% nextDamage
            Vect.reduceHealth(MM.damage*(1-vectorShield.save))
            gru.reduceEnergy(MM.energy)
            MM.resource-=1
            nextDamage=0.2 # 20% nextDamage
            break
    
        elif(gruWeapon=="KM" and KM.resource !=0):
            Vect.reduceHealth(KM.damage) #can't avoid it
            gru.reduceEnergy(KM.energy)
            KM.resource-=1
            break
        else:
             gruWeapon=input("Gru's Weapon: ")
            
            
      
               
        
    ## Vector's turn and Gru's turn to defend himself
    gruShield=input("Gru's Shield: ")
    if (gruShield=="SP" and SP.resource ==0):
        print("SP is not available")
        print("auto switching to EPB shield")
        gruShield=EPB
    else:
        gruShield=SP
        SP.resource-=1    
        
    vectorWeapon=random.choice(["LB","PG","SRC"])    
    if(vectorWeapon=="LB"):# 50 energy, 11 damage
        gru.reduceHealth(LB.damage*(1-gruShield.save))
        Vect.reduceEnergy(LB.energy)
    elif(vectorWeapon=="PG" and PG.resource !=0):
        gru.reduceHealth(PG.damage*(1-gruShield.save))
        Vect.reduceEnergy(PG.energy)
        PG.resource-=1
    elif(vectorWeapon=="SRC" and SRC.resource !=0):
        gru.reduceHealth(SRC.damage*(1-gruShield.save))
        Vect.reduceEnergy(SRC.energy)
        SRC.resource-=1
    else:
        print("vector's weapon is not available")# 50 energy, 11 damage
        print("auto switching to LB weapon")
        gru.reduceHealth(LB.damage*(1-gruShield.save))
        Vect.reduceEnergy(LB.energy)
     
    print("Gru's Health = ",gru.health,"     Gru's Energy =",gru.energy,"             Vector's Health = ",Vect.health,"   Vector's Energy = ",Vect.energy)
    if(gru.health<=0 or Vect.health<=0):# if one of them is dead
        bol=False
        break
    print("Next Turn")
    print("----------------------------------------------------------")
    print("----------------------------------------------------------")
    print("----------------------------------------------------------")
 

       
    
            


            
    
    


