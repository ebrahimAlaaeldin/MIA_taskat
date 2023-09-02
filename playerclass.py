class villainPlayer():
    
    def __init__(self,name,health=100,energy=500) :
        self.health = health
        self.energy = energy
        self.name = name
        
    def reduceHealth(self,damage):
        self.health -= damage
    def reduceEnergy(self,energy):
        self.energy -= energy
                
    
    
class GruWeapon():
    
    def __init__(self,name,energy,damage,avoidence=0,nextDamage=0, resource=-1 ): # -1 means inf
        self.energy = energy
        self.name = name
        self.damage = damage
        self.avoidence = avoidence
        self.resource=resource
        
    
class GruShields():
    
    def __init__(self,name,energy,save, resource=-1 ): # -1 means inf
        self.name = name
        self.energy = energy
        self.save = save
        self.resource=resource

class VectorWeapon():
    
    def __init__(self,name,energy,damage, resource=-1 ): # -1 means inf
        self.energy = energy
        self.name = name
        self.damage = damage
        self.resource=resource
        
        
class VectorShields():
    
    def __init__(self,name,energy,save, resource=-1 ): # -1 means inf
        self.name = name
        self.energy = energy
        self.save = save
        self.resource=resource
                    

   
   