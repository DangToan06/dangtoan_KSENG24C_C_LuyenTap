#include<stdio.h>
#include<math.h>
#include<limits.h>

int main(){
    int arr[100], n, number, addNumber, position, searchNumber, arr2[100];
    do{
        printf("\n\n\tMENU\n");
        printf("1.Nhap so luong va gia tri cho cac phan tu\n");
        printf("2.In mang (arr[0]=..., arr[1]=...)\n");
        printf("3.Dem so luong so hoan hao\n");
        printf("4.Dem so luong so nguyen to\n");
        printf("5.Tim gia tri lon thu 2(Khong xap xep)\n");
        printf("6.Tim gia tri nho thu 2(Khong xap xep)\n");
        printf("7.Them Phan tu tai vi tri\n");
        printf("8.Xoa phan tu tai vi tri\n");
        printf("9.Xap xep mang tang dan(Xap xep chen)\n");
        printf("10.Xap xep mang giam dan(Xap xep chen)\n");
        printf("11.Tim kiem phan tu(Tim kiem nhi phan)\n");
        printf("12.Xoa phan tu trung lap va in phan tu doc nhat\n");
        printf("13.Xap xep va kien thi so chan dung truoc so le dung sau\n");
        printf("14.Dao nguoc mang\n");
        printf("15.Thoat\n");
        printf("\nNhap lua chon cua ban: ");
        scanf("%d", &number);
        int sum = 0, count = 0;
        int min = INT_MAX, min2 = INT_MAX;
        int max = INT_MIN, max2 = INT_MIN;
        int check;
        switch(number){
            case 1:
                printf("Nhap do dai mang: ");
                scanf("%d", &n);
                while(n <= 0){
                    printf("Mang ban nhap khong duoc nho hoac bang 0\n");
                    printf("Nhap lai: ");
                    scanf("%d", &n);
                }
                printf("Nhap gia tri cho mang:\n");
                for(int i = 0; i < n; i++){
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    printf("Mang ban vua nhap:\n");
                    for(int i = 0; i < n; i++){
                        printf("arr[%d] = %d\n", i, arr[i]);
                    }
                }
                break;
            case 3:
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    for(int i = 0; i < n; i++){
                        sum = 0;
                        for(int j = 1; j < arr[i]; j++){
                            if(arr[i] % j == 0){
                                sum += j;
                                if(sum == arr[i]){
                                    count++;
                                }
                            }
                        }
                    }
                    printf("so luong so hoan hao trong mang tren la: %d", count);
                }
                break;
            case 4:
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    for(int i = 0; i < n; i++){
                        check = 1;
                        if(arr[i] <= 1){
                            check = 0;
                        }
                        for(int j = 2; j <= sqrt(arr[i]); j++){
                            if(arr[i] % j == 0){
                                check = 0;
                            }
                        }
                        if(check == 1){
                            count++;
                        }
                    }
                    printf("So luong so nguyen to la: %d", count);
                }
                break;
            case 5:
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    for(int i = 0; i < n; i++){
                        if(arr[i] > max){
                            max2 = max;
                            max = arr[i];
                        }else if(arr[i] > max2 && arr[i] != max){
                            max2 = arr[i];
                        }
                    }
                    printf("Gia tri lon thu 2 la: %d", max2);
                }
                break;
            case 6:
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    for(int i = 0; i < n; i++){
                        if(arr[i] < min){
                            min2 = min;
                            min = arr[i];
                        }else if(arr[i] < min2 && arr[i] != min){
                            min2 = arr[i];
                        }
                        
                    }
                    printf("Gia tri nho thu 2 la: %d", min2);
                }
                break;
            case 7:
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    printf("Moi nhap gia tri muon them: ");
                    scanf("%d", &addNumber);
                    printf("Vi tri muon them: ");
                    scanf("%d", &position);
                    while(position <= 0 || position > n){
                        printf("Gia tri ban nhap khong nam trong khoang\nNhap la: ");
                        scanf("%d", &position);
                    }
                    n = n + 1;
                    for(int i = n; i >= position; i--){
                        arr[i] = arr[i-1];
                    }
                    printf("Mang sau khi duoc them vao la:\n");
                    for(int i = 0; i < n; i++){
                        if(i == position - 1){
                            arr[i] = addNumber;
                        }
                        printf("%d ", arr[i]);
                    }
                }
                break;
            case 8:
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    printf("Nhap gia tri ban muon xoa: ");
                    scanf("%d", &position);
                    while(position <= 0 || position > n){
                        printf("Gia tri ban nhap khong nam trong khoang\nNhap la: ");
                        scanf("%d", &position);
                    }
                    n = n - 1;
                    for(int i = position - 1; i < n; i++){
                        arr[i] = arr[i + 1];
                    }
                    printf("Mang sau khi duoc xoa la:\n");
                    for(int j = 0; j < n; j++){
                        printf("%d ", arr[j]);
                    }
                }
                break;
            case 9:
                int j;
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    for(int i = 0; i < n; i++){
                        int key = arr[i];
                        for(j = i - 1; j >= 0 && key < arr[j]; j--){
                            arr[j + 1] = arr[j];
                        }
                        arr[j + 1] = key;
                    }
                    printf("Mang sau khi duoc sap xep la:\n");
                    for(int i = 0; i < n; i++){
                        printf("%d ", arr[i]);
                    }
                }
                break;
            case 10:
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    for(int i = 0; i < n; i++){
                        int key = arr[i];
                        for(j = i - 1; j >= 0 && key > arr[j]; j--){
                            arr[j + 1] = arr[j];
                        }
                        arr[j + 1] = key; 
                    }
                    printf("Mang sau khi duoc xap sep la:\n");
                    for(int i = 0; i < n; i++){
                        printf("%d ", arr[i]);
                    }
                }
                break;
            case 11:
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    printf("Nhap phan tu ban muon tim kiem: ");
                    scanf("%d", &searchNumber);
                    int start = 0;
                    int end = n;
                    int mid;
                    check = 0;
                    while(start <= end){
                        mid = (start + end)/2;
                        if(arr[mid] == searchNumber){
                            check = 1;
                            printf("Phan tu ton tai trong mang");
                            break;
                        }else if(arr[mid] > searchNumber){
                            end = mid - 1;
                        }else if(arr[mid] < searchNumber){
                            start = mid + 1;
                        }
                    }
                    if(check == 0){
                        printf("Phan tu khon ton tai trong mang");
                    }  
                }
                break;
            case 12:
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    printf("Phan tu doc nhat la:\n");
                    for(int i = 0; i < n; i++){
                        count = 0;
                        for(int j = 0; j < n; j++){
                            if(arr[i] == arr[j]){
                                count++;
                            }
                        }
                        if(count == 1){
                            printf("%d ", arr[i]);
                        }
                    }  
                }
                break;
            case 13:
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    count = 1;
                    j = 0;
                    for(int i = 0; i < n; i++){
                        if(arr[i] % 2 == 0){
                            arr2[j] = arr[i];
                            j++;
                        }else if(arr[i] % 2 != 0){
                            arr2[n - count] = arr[i];
                            count++;
                        }
                    }
                    printf("Mang co so chan dung truoc so le dung sau:\n");
                    for(int i = 0; i < n; i++){
                        printf("%d ", arr2[i]);
                    }
                }
                break;
            case 14:
                if(n == 0){
                    printf("Ban chua nhap gia tri nao cho mang");
                }else{
                    for(int i = 0; i < n/2; i++){
                        int temp = arr[n - 1 - i];
                        arr[n - i - 1] = arr[i];
                        arr[i] = temp;
                    }
                    printf("Mang sao nguoc\n");
                    for(int i = 0; i < n; i++){
                        printf("%d ", arr[i]);
                    }
                }
                break;
            case 15:
                break;
            default:
                printf("Phan tu ban nhap khong co trong MENU");
        }
    }while(number != 15);
    
    return 0;
}