# -*- coding: ISO-8859-2 -*-
'''
Created on 17.06.2017

@author: Tomek

losuje sie 7 plytek
'''
import itertools as it

class ScrabbleHelper:
    
    def __init__(self):
        self.setDictionaryWords = set()
        self.setPossibleWords = set()
        self.loadWordListFromFile('slowa.txt')
    
    def loadWordListFromFile(self,filename):
        with open(filename, 'r') as fp:
            self.setDictionaryWords = set(fp.read().splitlines())
    
    def getDictionaryWords(self):
        return self.setDictionaryWords
        
    def genSetPossibleWords(self, tabletsLetters, mini, maxi):
        size = len(tabletsLetters)
        for i in range(mini,maxi+1):
            perms=set(it.permutations(tabletsLetters,i))
            for el in perms:
                self.setPossibleWords.add(''.join(el))
        return self.setPossibleWords
    

# if __name__ == '__main__':
#     sw = ScrabbleHelper()
    
#     wholeDictionary = sw.getDictionaryWords() #load all txt
#     possibleWords = sw.genSetPossibleWords('���tay',1,122)
#     czestWspolna = wholeDictionary & possibleWords
    
#     #print(len(possibleWords)) 
#     #print(len(czestWspolna))
#     for wyraz in czestWspolna:
#         print(wyraz)
    
#     #sw.generatePermutationsWithStar()