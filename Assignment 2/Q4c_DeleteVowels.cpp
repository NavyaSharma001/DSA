#include <iostream>
using namespace std;
bool isVowel(char ch){
    if(ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';
    return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}
int main(){
    char str[] = "Hello World";
    char result[100];
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(!isVowel(str[i])) result[j++] = str[i];
    }
    result[j] = '\0';
    cout << "String without vowels: " << result;
    return 0;
}