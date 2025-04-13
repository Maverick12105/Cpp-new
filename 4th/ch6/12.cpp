#include <iostream>
using namespace std;
#include <fstream>

const int BOXSIZE = 3;
const int POSSIBLEPRODUCE = 5;
const string FILEPATH = "D:\\homework\\C++ new\\4th\\ch6\\Produce_list.txt";

class BoxOfProduce{
    public:
        void setProduce(int index, string produce);
        string getProduce(int index);
        void displayContent();
    private:
        string content[BOXSIZE];
};

int main(){
    fstream produce_file;
    string produce_list[POSSIBLEPRODUCE];
    BoxOfProduce box;
    char substitute;
    int substitute_from, subsitute_to;

    produce_file.open(FILEPATH);
    for(int i = 0; i < POSSIBLEPRODUCE; ++i)
        produce_file >> produce_list[i];
    produce_file.close();

    for(int i = 0; i < BOXSIZE; ++i)
        box.setProduce(i, produce_list[rand() % 5]);

    while(true){
        box.displayContent();
        cout << "Do you wish to substitute any? (y/n) => ";
        cin >> substitute;
        if(substitute != 'y')
            break;
        cout << "which one? (1/2/3) => ";
        cin >> substitute_from;
        cout << endl;
        for(int i = 0; i < POSSIBLEPRODUCE; ++i)
            cout << i + 1 << '.' << produce_list[i] << endl;
        cout << "with which? (1/2/3/4/5) => ";
        cin >> subsitute_to;
        cout << endl;
        box.setProduce(substitute_from - 1, produce_list[subsitute_to - 1]);
    }
    
    cout << endl;
    box.displayContent();
    cout << "Will be deliver.";
    
    return 0;
}

void BoxOfProduce::setProduce(int index, string produce){
    content[index] = produce;
}

string BoxOfProduce::getProduce(int index){
    return content[index];
}

void BoxOfProduce::displayContent(){
    cout << "The box is contain of " << endl;
    for (int i = 0; i < BOXSIZE; ++i)
        cout << i + 1 << '.' << content[i] << endl;
}

/*
Your Community Supported Agriculture (CSA) farm delivers a box of fresh fruits and vegetables to your house once a week.
For this programming Project, define the class BoxOfProduce that contains exactly three bundles of fruits or vegetables. 
You can represent the fruits or vegetables as an array of type string. 
Add accessor and mutator functions to get or set the fruits or vegetables stored in the array. 
Also write an output function that displays the complete contents of the box on the console.
Next, write a main function that creates BoxOfProduce with three items randomly selected from this list: 
    Broccoli
    Tomato
    Kiwi
    Kale
    Tomatillo
This list should be stored in a text file that is read in by your program. 
For now you can assume that the list contains exactly five types of fruits or vegetables. 
Do not worry if your program randomly selects duplicate produce for the three items.
Next, the main function should display the contents of the box 
and allow the user to substitute any one of the five possible fruits or vegetables for 
any of the fruits or vegetables selected for the box. 
After the user is done with substitutions output the final contents of the box to be delivered. 
*/