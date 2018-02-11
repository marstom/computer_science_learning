/* make tree03
 * 
 * test:
 * a.out < tests/file1.txt
 * 
 * Spellchecker
 * Usage:
 *
 * spellchecker < file.txt
 * perfc++
 * assert.h do testow
 * google.test
 *
 */

#include "bst.hpp"

using namespace std;

void read_whole_pl_dictionary(BstNode* bigDictionary){
    /*
     * read file with dictionary.
     * */
    ifstream inputFile;
    string line;
    int cnt=0;
    inputFile.open("slowa.txt");
    //inputFile.open("./scrabblehelper_set/slowa.txt"); // >2M words!!! C++ is slower than python :(


    while(getline(inputFile, line)){
        insert(bigDictionary, line);
        cnt++;
        if(cnt%10000==0) printf("read ... %d \n", cnt);
    }
    printf("Wczytano plik\n");

    inputFile.close();
}

void spell_checker(BstNode *dict){
    /*
     * if not found word print typo
     * TODO in which line?
     */
    string word;
    while(cin >> word){
       // cout << word;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        bool correct = (bool)is_in_tree(dict, word);
        if(!correct) 
            cout << "Typo! in: " << word << endl;
    } 
}

void test_insert(){
    BstNode* root = new BstNode(); //why it works without new?
    root->data="ZaRon";
    insert(root,"Adam");	
    insert(root,"ZzAnna");	
    insert(root,"Roman");
    insert(root,"Staszek");
    insert(root,"Ronaldo");
    insert(root,"Regan");
    
    insert(root,"Zegan");
    insert(root,"Eegan");
    insert(root,"Logan");
    insert(root,"Rdsgan");
    insert(root,"AaKaan"); // 12

    
    cout<<"is_in_treeed word\n";
    string name = "Ronaldo";
    //If name is found, print "FOUND"
    if(is_in_tree(root,name) == true) 
        cout<<"Found\n";
    else 
        cout<<"Not Found\n";
    cout << "Min element: " << findMinimum(root) << endl;
    cout << "Max element: " << findMaximum(root) << endl;
    // assert (1==1);
    // assert (0==1);
    cout << "*******\n";
    print_values(root);
    cout << "*******\n";
    cout << "Size : " << get_node_count(root) << endl;
    cout << "Height: " << get_height(root) << endl;


}

void test_read_dictionary(){
    BstNode *bigDictionary = new BstNode();
    read_whole_pl_dictionary(bigDictionary);
    cout << "Nodes:" << endl;
}

void program_spell_checker(){
    BstNode *bigDictionary = new BstNode();
    read_whole_pl_dictionary(bigDictionary);
    spell_checker(bigDictionary);
}

int main(){
    test_insert();
    test_read_dictionary();
    // program_spell_checker();
    return 0;
}
