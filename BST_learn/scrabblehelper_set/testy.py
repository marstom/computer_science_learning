# -*- coding: ISO-8859-2 -*-
'''
Created on 17.06.2017

@author: Tomek
'''

def test_zbiory_sety():
    mieszane = {'kot', 'czosnek','marchew', 'pies', 'lis'}
    warzywa = {'czosnek', 'marchew', 'strąkiew'}
    
    print(warzywa & mieszane) #cz�c wsp�lna zbiorow

if __name__ == '__main__':
    with open('test.txt','r') as fp:
        for el in fp:
            print(el.strip('\r\n'))