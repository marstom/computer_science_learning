'''
Created on 17.06.2017

@author: Tomek
'''
import pickle
import time

def genWordList(filename): 
    setDictionaryWords=set()      
    file = open(filename, 'r')
    for el in file:
        setDictionaryWords.add(el.strip('\r\n'))
    file.close()
    return setDictionaryWords

def dumpToBinary(): 
    setDictionaryWords=set()      
    file = open('slowa.txt','r')
    for el in file:
        setDictionaryWords.add(el.strip('\r\n'))
    file.close()
    
    with open('./wordBinaryFile.dat', 'wb') as fp:
        pickle.dump(setDictionaryWords, fp)
    
def loadSetFromFile(filename):
    with open(filename, 'rb') as fp:
        setDictionaryWords = pickle.load(fp)
    return setDictionaryWords

if __name__ == '__main__':
    #dumpToBinary() 
    st = time.clock()
    #wordSet = loadSetFromFile('wordBinaryFile.dat')    #1.37
    wordSetFromTxt = genWordList('slowa.txt')           #2.09
    evalu = time.clock() - st
    print(evalu)
