# -*- coding: ISO-8859-2 -*-
'''
Created on 17.06.2017

@author: Tomek
'''

class Page:

    page='''
<head>
<link rel="stylesheet" type="text/css" href="wzor.css">
</head>

<table>
<tbody>

    {mid}

</tbody>
</table>
'''
    
    table='''
    <tr>
        <td>{id}</td>
        <td>{word}</td>
    </tr>
    '''
    
    def __init__(self):
        self.middle=''
        self.htmlText = self.page

        
    def addRow(self, id, napis):
        self.middle += self.table.format(id=id, word=napis)
        
    def savePage(self):
        self._buildPage()
        with open('index.html', 'w') as page:
            page.write(self.htmlText)
    
    def _buildPage(self):
        self.htmlText = self.htmlText.format(mid=self.middle)

if __name__ == '__main__':
    pa = Page()
    pa.addRow(112, 'napis')
    pa.addRow(112, 'napis')
    pa.addRow(12, 'napis')
    pa.addRow(12, 'napis')
    pa.savePage()