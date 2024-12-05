#include <stdio.h>

int main (){
	int arr[100];
	int choice, i, size=0, pos, temp;
	
	do{
		printf("\nMENU\n");
		printf("1. Nhap so phan tu va gia tri cho mang\n");
		printf("2. In ra cac gia tri phan tu trong mang\n");
		printf("3. So luong cac so hoan hao co trong mang\n");
		printf("4. Gia tri nho thu 2 trong mang\n");
		printf("5. Them mot phan tu vao vi tri dau tien trong mang\n");
		printf("6. Xoa phan tu\n");
		printf("7. Sap xep mang theo thu tu giam gian\n");
		printf("8. Kiem tra xem phan tu co ton tai trong mang hay khong\n");
		printf("9. Sap xep mang so le dung truoc, so chan dung sau\n");
		printf("10. Dao nguoc thu tu cac phan tu va hien thi ra toan bo phan tu co dang(arr[0]=1-le,arr[1]=2-chan...)\n");
		printf("11. Thoat chuong trinh\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
            printf("\nNhap so phan tu: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++) {
                printf("Nhap phan tu arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }
            break;
        case 2:
            printf("\nCac phan tu trong mang: \n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]= %d\n ", i, arr[i]);
            }
            break;
        case 3:{ 
                int count=0;
                for(int i=0; i<size; i++){
                    int sum=1; 
                    for(int j=2; j*j<=arr[i]; j++){
                        if(arr[i] % j == 0){
                            sum += j + (arr[i] / j == j ? 0 : arr[i] / j);
                        }
                    }
                    if(sum == arr[i] && arr[i] > 1){
                        count++;
                    }
                }
                printf("\nSo luong so hoan hao trong mang: %d\n", count);
                break;
            }
            case 4: {
                if(size<2){
                    printf("Mang khong du phan tu de tim gia tri nho thu 2\n");
                } else {
                    int min = arr[0], min2 = __INT_MAX__;
                    for(int i=0; i<size; i++){
                        if (arr[i] < min){
                            min2 = min;
                            min = arr[i];
                        }else if (arr[i] > min && arr[i] < min2){
                            min2 = arr[i];
                        }
                    }
                    if (min2 == __INT_MAX__){
                        printf("Khong co gia tri nho thu 2\n");
                    }else{
                        printf("Gia tri nho thu 2 trong mang: %d\n", min2);
                    }
                }
                break;
            }
            case 5:{ 
                int newE;
                printf("Nhap gia tri can them: ");
                scanf("%d", &newE);
                for(int i=size; i>0; i--){
                    arr[i] = arr[i-1];
                }
                arr[0] = newE;
                size++;
                printf("Da them phan tu\n");
                break;
            }
            case 6:{ 
                printf("Nhap vi tri phan tu can xoa (0 - %d): ", size-1);
                scanf("%d", &pos);
                if(pos >= 0 && pos<size){
                    for(int i=pos; i<size-1; i++){
                        arr[i] = arr[i+1];
                    }
                    size--;
                    printf("Da xoa phan tu\n");
                } else {
                    printf("Vi tri khong hop le\n");
                }
                break;
            }
            case 7:{ 
                for(int i=0; i<size-1; i++){
                    for(int j=i+1; j<size; j++){
                        if (arr[i] < arr[j]) {
                            temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep giam dan: \n");
                for(int i=0; i<size; i++){
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            }
            case 8:{ 
                int x, found = 0;
                printf("Nhap gia tri can kiem tra: ");
                scanf("%d", &x);
                for (int i=0; i<size; i++){
                    if (arr[i] == x) {
                        found=1;
                        break;
                    }
                }
                if(found){
                    printf("Gia tri %d co ton tai trong mang\n", x);
                } else {
                    printf("Gia tri %d khong ton tai trong mang\n", x);
                }
                break;
            }
            case 11:
                printf("Thoat chuong trinh\n");
                break;

            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 11);

    return 0;
}
