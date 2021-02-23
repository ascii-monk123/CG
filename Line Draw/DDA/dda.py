import math
#this module will emulate dda line draw algorithm

class DDA():
    #initial points for dda
    def __init__(self,x0,x1,y0,y1):
        self.x=[x0,x1]
        self.y=[y0,y1]
        self.pattern=''.center(20,'-')
        print('\n'+self.pattern)
        print('Points initialized\n')
        print(self.pattern)
        print('(x0,y0) => ({},{})\n'.format(x0,y0))
        print('(x1,y1) => ({},{})\n'.format(x1,y1))
    
    #will generate points based on config,returns True operation success else False
    #great=>slope>1
    #less=>slope<1
    #equal=>slope=1
    def generatePoints(self:object,slope:float,config:str="great")->bool:
        self.pointList=[(self.x[0],self.y[0])]
        self.absPoints=[(self.x[0],self.y[0])]
        reachedFinalPoint=False
        while(not reachedFinalPoint):
            x=self.pointList[len(self.pointList)-1][0]
            y=self.pointList[len(self.pointList)-1][1]
            if config=="great":
                x+=(1/slope)
                y+=1
            elif config=="less":
                x+=1
                y+=slope
            elif config=="equal":
                x+=1
                y+=1
            else:
                print(self.pattern+'\n')
                print('Line cannot be drawn\n')
                print(self.pattern+'\n')
                return False
            
            self.pointList.append((x,y))
            self.absPoints.append((round(x),round(y)))
            if round(x)==self.x[1] and round(y)==self.y[1]:
                reachedFinalPoint=True
            elif round(x)>self.x[1] or round(y)>self.y[1]:
                print('Line cannot be drawn\n')
                return False
        return True
        
    
    #the method which contains the algo to find the coordinates of points in the roster i.e pixel location
    def findPoints(self):
        if abs(self.x[1]-self.x[0])==0:
            slope=math.inf
        else:    
            #calculate the slope
            slope=(self.y[1]-self.y[0])/(self.x[1]-self.x[0])
        print(self.pattern)
        print('\nSlope is m = {}'.format(slope))

        if abs(slope)>1:
            return self.generatePoints(slope,'great')
        elif  abs(slope)==1:
            return self.generatePoints(slope,'equal')
        else:
            return self.generatePoints(slope,'less')


try:
    print('\n************\n')
    print('Enter the initial coordinates and the final coordinates of the points like: x0 y0 x1 y1\n')
    (x0,y0,x1,y1)=list(map(int,input().split(" ")))
except Exception as E:
    print(E)
    exit()
ddaController=DDA(x0,x1,y0,y1)
pts=ddaController.findPoints()
if pts:
    print('\n'+ddaController.pattern+'\n')
    print('The generated points are: \n')
    print(ddaController.absPoints)
    print(ddaController.pattern+'\n')
else:
    exit()