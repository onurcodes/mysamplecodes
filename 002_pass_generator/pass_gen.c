///PASSWORD GENERATOR
///This is for educational purposes only!
///USING THIS CODE IS AT YOUR RESPONSIBILITY!
///THE AUTHOR IS CAN'T BE BLAMED FOR ILLEGAL USE!
///BY USING THIS CODE YOU ACCEPT THIS AGREEMENT!


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <ncurses.h>
#include <string.h>

#define START_ASCII 97//a
#define END_ASCII 121
#define START_LENGTH 8
#define END_LENGTH 9//63


char* generate_char_array(int* iArray,int length){
    char* ret_char_array;
    ret_char_array=(char*)malloc(length*sizeof(char));
    int i = 0;
    for(i = 0; i < length; i++){
        ret_char_array[i]=START_ASCII+(char)iArray[i];
    }
    return ret_char_array;

}
/// COMBINATION CODE IS TAKEN FROM THIS ADRESS:
/// https://helloacm.com/cc-coding-exercise-recursive-combination-algorithm-implementation/
void comb(int n, int r, int *arr, int sz) {
    for (int i = n+1; i >= 0; i --) {
        // choose the first element
        arr[r - 1] = i;
        if (r > 1) { // if still needs to choose
            // recursive into smaller problem
            comb(i - 1, r - 1, arr, sz);
        } else {

            char* dizi=generate_char_array(arr,sz);
            char buffer [128];
            //sprintf (buffer, "nmcli d wifi connect %s password %s iface wlan0", "SSID ADI", dizi);
            printf("dizi = %s",dizi);
            //system(buffer)

            free(dizi);
            printf("\n");

        }
    }
}
int main() {

    //nmcli d wifi connect <WiFiSSID> password <WiFiPassword> iface wlan0

    int range_ascii = END_ASCII-START_ASCII;
    int range_length = END_LENGTH-START_LENGTH;

    for(int i = START_LENGTH; i <= END_LENGTH+1;i++){
        int *arr = new int[i];
        comb(range_ascii, i, arr, i);
        free(arr);


    }


    return 0;
}
