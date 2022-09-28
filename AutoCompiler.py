import glob
import os

def Main():
    repeat=True
    while repeat:
        repeat=False
        list_of_files = glob.glob('C:\\Users\\kevin\\Desktop\\Università\\Fondamenti 2\\*.cpp') # * means all if need specific format then *.csv
        latest_file = max(list_of_files, key=os.path.getmtime)
        latest_file=Pulire(latest_file)
        path="C:\\Users\\kevin\\Desktop\\Università\\Fondamenti 2\\"
        comando="g++ -std=c++11 -o "+"\""+path+latest_file+"\""+" "+"\""+path+latest_file+".cpp"+"\""
        tmp=os.system(comando)
        if tmp!=0:
            os.system("pause")
            os.system("cls")
            repeat=True
        


def Pulire(x):
    risultato=""
    for i in range(len(x)):
        if x[i]==".":
            return risultato
        risultato+=x[i]
        if x[i]=="\\":
            risultato=""

Main()