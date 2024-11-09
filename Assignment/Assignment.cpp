#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_AUTHOR 100

typedef struct {
    char id[7]; 
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int year;
    char genre[MAX_TITLE];
    int quantity;
} Book;

Book books[MAX_BOOKS];
int book_count = 0;

void add_book();
void display_books();
void find_book();
void remove_book();
void update_book();
void save_to_file();
int is_valid_id(const char *id);
int is_valid_string(const char *str);

int main() {
    int choice;
    do {
        printf("\n--- Quản lý sách thư viện ---\n");
        printf("1. Thêm sách\n");
        printf("2. Hiển thị danh sách sách\n");
        printf("3. Tìm kiếm sách theo mã\n");
        printf("4. Xóa sách theo mã\n");
        printf("5. Sửa thông tin sách\n");
        printf("6. Lưu thông tin ra file\n");
        printf("0. Thoát\n");
        printf("Chọn chức năng: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_book(); break;
            case 2: display_books(); break;
            case 3: find_book(); break;
            case 4: remove_book(); break;
            case 5: update_book(); break;
            case 6: save_to_file(); break;
            case 0: printf("Thoát chương trình.\n"); break;
            default: printf("Lựa chọn không hợp lệ!\n");
        }
    } while (choice != 0);

    return 0;
}

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Kho sách đầy!\n");
        return;
    }
    
    Book new_book;
    printf("Nhập mã sách (XXYYYY): ");
    scanf("%6s", new_book.id);
    if (!is_valid_id(new_book.id)) {
        printf("Mã sách không hợp lệ!\n");
        return;
    }

    printf("Nhập tên sách: ");
    scanf(" %[^\n]", new_book.title);
    if (!is_valid_string(new_book.title)) {
        printf("Tên sách không hợp lệ!\n");
        return;
    }

    printf("Nhập tên tác giả: ");
    scanf(" %[^\n]", new_book.author);
    if (!is_valid_string(new_book.author)) {
        printf("Tên tác giả không hợp lệ!\n");
        return;
    }

    printf("Nhập năm xuất bản: ");
    scanf("%d", &new_book.year);
    printf("Nhập thể loại: ");
    scanf(" %[^\n]", new_book.genre);
    printf("Nhập số lượng: ");
    scanf("%d", &new_book.quantity);

    books[book_count++] = new_book;
    printf("Thêm sách thành công!\n");
}

void display_books() {
    printf("\nDanh sách sách:\n");
    printf("Mã sách\t\tTên sách\t\tTác giả\t\tNăm xuất bản\tThể loại\tSố lượng\n");
    for (int i = 0; i < book_count; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t%d\n", 
            books[i].id, books[i].title, books[i].author, books[i].year, books[i].genre, books[i].quantity);
    }
}

void find_book() {
    char id[7];
    printf("Nhập mã sách cần tìm: ");
    scanf("%6s", id);
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].id, id) == 0) {
            printf("Thông tin sách:\n");
            printf("Mã sách: %s\n", books[i].id);
            printf("Tên sách: %s\n", books[i].title);
            printf("Tác giả: %s\n", books[i].author);
            printf("Năm xuất bản: %d\n", books[i].year);
            printf("Thể loại: %s\n", books[i].genre);
            printf("Số lượng: %d\n", books[i].quantity);
            return;
        }
    }
    printf("Không tìm thấy sách với mã: %s\n", id);
}

void remove_book() {
    char id[7];
    printf("Nhập mã sách cần xóa: ");
    scanf("%6s", id);
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].id, id) == 0) {
            for (int j = i; j < book_count - 1; j++) {
                books[j] = books[j + 1];
            }
            book_count--;
            printf("Xóa sách thành công!\n");
            return;
        }
    }
    printf("Không tìm thấy sách với mã: %s\n", id);
}

void update_book() {
    char id[7];
    printf("Nhập mã sách cần sửa: ");
    scanf("%6s", id);
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].id, id) == 0) {
            printf("Nhập tên sách mới: ");
            scanf(" %[^\n]", books[i].title);
            printf("Nhập tên tác giả mới: ");
            scanf(" %[^\n]", books[i].author);
            printf("Nhập năm xuất bản mới: ");
            scanf("%d", &books[i].year);
            printf("Nhập thể loại mới: ");
            scanf(" %[^\n]", books[i].genre);
            printf("Nhập số lượng mới: ");
            scanf("%d", &books[i].quantity);
            printf("Cập nhật sách thành công!\n");
            return;
        }
    }
    printf("Không tìm thấy sách với mã: %s\n", id);
}

void save_to_file() {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Lỗi mở file!\n");
        return;
    }
    for (int i = 0; i < book_count; i++) {
        fprintf(file, "%s,%s,%s,%d,%s,%d\n", 
            books[i].id, books[i].title, books[i].author, books[i].year, books[i].genre, books[i].quantity);
    }
    fclose(file);
    printf("Lưu thông tin sách thành công!\n");
}

int is_valid_id(const char *id) {
    if (strlen(id) != 6) return 0;
    for (int i = 0; i < 2; i++) {
        if (!isalpha(id[i])) return 0; 
    }
    for (int i = 2; i < 6; i++) {
        if (!isdigit(id[i])) return 0; 
    }
    return 1;
}

int is_valid_string(const char *str) {
    if (strlen(str) == 0) return 0; 
    for (int i = 0; i < strlen(str); i++) {
        if (ispunct(str[i])) return 0; 
    }
    return 1;
}
