# -*- coding: ISO-8859-2 -*-
'''
Created on 17.06.2017

@author: Tomek
'''
from wordGenerator import ScrabbleHelper
from cgiInterface import Page
import sys

def main(args):
    tilesSetYouHave = args[1]
    minimum = int(args[2])
    maximum = int(args[3])
    scrabbleHelper = ScrabbleHelper()
    dictionaryWords = scrabbleHelper.getDictionaryWords()

    possibleWords = scrabbleHelper.genSetPossibleWords(tilesSetYouHave, minimum, maximum)
    
    czescWspolna = dictionaryWords & possibleWords
    czescWspolna = list(czescWspolna)
    czescWspolna = sorted(czescWspolna)
    # create HTML
    page = Page()
    id_=0
    for napis in czescWspolna:
        id_+=1
        page.addRow(id_, napis)
    
    page.savePage()
    
    # print summary
    communicate = '''
    Possible words = {}
    Dict words = {}
    Found results = {}
    '''.format(len(possibleWords), len(dictionaryWords), len(czescWspolna))
    print(communicate)

if __name__ == '__main__':
    print(len(sys.argv))
    print(sys.argv)
    if len(sys.argv)>1:
        main(sys.argv)
    else:
        print('''
    Usage:
        main.py characters min max
        characters - set of characters
        min - minimum word length
        max - maximum word length
        ''')
