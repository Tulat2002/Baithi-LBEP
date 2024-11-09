#include <stdio.h>
#include <string.h>

#define NUM_CLASSROOMS 10

struct ClassRoom {
    char roomName[50];
    int roomNo;
};

void inputClassRooms(struct ClassRoom classRooms[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Nhap thong tin lop %d:\n", i + 1);
        
        printf("Room name: ");
        scanf(" %[^\n]%*c", classRooms[i].roomName); 
        
        printf("Room no: ");
        scanf("%d", &classRooms[i].roomNo);
        
        printf("\n");
    }
}

void displayClassRooms(struct ClassRoom classRooms[], int size) {
    printf("thong tin lop:\n");
    for (int i = 0; i < size; i++) {
        printf("Room name: %s\n", classRooms[i].roomName);
        printf("Room no: %d\n\n", classRooms[i].roomNo);
    }
}

int main() {
    struct ClassRoom classRooms[NUM_CLASSROOMS];
    
    
    inputClassRooms(classRooms, NUM_CLASSROOMS);
    
    
    displayClassRooms(classRooms, NUM_CLASSROOMS);
    
    return 0;
}
