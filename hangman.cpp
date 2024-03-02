#include <iostream>
#include <string>
#include <vector>
#include <ctime>

std::string getAnimal(std::vector<std::string>);

void printBlanks(std::string mysteryWord);

char getLetter();

bool validateLetter(std::string, char);

int main(){

    srand(time(nullptr));

    std::vector<std::string> animals = {
        "dog",
        "cat",
        "elephant",
        "lion",
        "tiger",
        "giraffe",
        "zebra",
        "bear",
        "wolf",
        "fox",
        "rabbit",
        "kangaroo",
        "horse",
        "cow",
        "sheep",
        "pig",
        "chicken",
        "duck",
        "goat",
        "deer"
    };

    //std::cout << animals.size() << std::endl;
    //The above line is is used to validate the number of elements in the vector

    std::string mysteryWord {getAnimal(animals)};

    printBlanks(mysteryWord);
    int mistakes {0};
    //std::cout << mysteryWord;
    //The above line ensures an animal is being displayed.
    do{
        if(validateLetter(mysteryWord, getLetter())){
            std::cout << "Letter is in word";
        }else{
            std::cout << "Letter is not in word";
            mistakes ++;
        }
    }while(mistakes < 10);
    return 0;
}

std::string getAnimal(std::vector <std::string> vec){
    std::string mysteryWord {};
    mysteryWord = vec.at((rand()%20));
    return mysteryWord;
}

void printBlanks(std::string mysteryWord){
    static std::string blanks {};
    for(auto letter: mysteryWord)
        blanks += "_ ";
    std::cout << blanks;
}

char getLetter(){
    char letter {};
    std::cout << "\nEnter a letter: ";
    std::cin >> letter;
    return letter;
}

bool validateLetter(std::string mysteryWord, char letter){
    bool isInWord {false};
    for(auto character: mysteryWord){
        if(character == letter){
            isInWord = true;
        }
    }
    return isInWord;
}
