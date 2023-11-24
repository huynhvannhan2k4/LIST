#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*
	KHAI BAO CAC THU VIEN, TIEN XU LY,
	THU VIEN stdlib.h LA THU VIEN CUA HAM malloc
*/


//Cau 1 - Khai bao cau truc DS Lien ket don chua cac so thuc

	// Kieu cua phan tu trong danh sach
typedef float ElementType;
	// Khai bao mot cau truc co ten la Node
struct Node {
	
	//Chua noi dung phan tu
	ElementType Elements;
	
	//con tro chi den phan tu ke tiep
	Node *Next;
/*	
	Doi voi duoi .cpp thi khoi struct,
	nhung doi voi duoi .c thi phai co tu struct o phia truoc no
*/ 
};
typedef Node *Position;
/*
	Dinh danh KDL moi co ten la Position,
	la mot kieu Node,
	co chuc nang nhu mot bien con tro kieu Node
*/
typedef Node *List;
/*
	Node *List = Position List ,
	tai vi Node *List la mot bien con tro co kieu la Node,
	con Position List 
*/

/*
	Khai bao DS cac chuong trinh con
*/

//Ham khoi tao DS rong
void MakeNull_List (List *L);

//Ham xen phan tu X vao vi tri P trong DS L
void Insert_List (ElementType X, Position P, List *L);

//Ham nhap danh sach L co n phan tu
void NhapDS(List *L, int n);

//Ham lay phan tu tai vi tri thu P cua DS L
ElementType Retrieve (Position P, List L);

//Ham in cac phan tu cua DS L
void XuatDS(List L);

//Ham tinh gia tri trung binh cua cac phan tu trong DS L
float TinhTB(List L);

//Ham xoa phan tu tai vi tri P trong DS L
void Delete_List (Position P, List *L);

//Ham Xoa phan tu thu k trong DS L
void XoaPT (int k, List *L);

//Ham xac dinh vi tri cua phan tu dau DS
Position First (List L);

//Ham xac dinh vi tri cua phan tu X trong DS L
Position Locate (ElementType X, List L);

//Ham xen hoac xoa phan tu X neu X khong co/Co trong DS
void Xen_XoaPT(ElementType X, List *L);

/*
	CT chinh
*/
int main(){
    int n, k;
	List L;
	ElementType X;
	  
    // Cau 2
	printf("\n Nhap so phan tu cua danh sach n = "); scanf("%d",&n);
	//Khoi tao danh sach rong
	MakeNull_List(&L);
	printf("\n Nhap cac phan tu cua danh sach L:");
	NhapDS(&L, n);
	printf("\n Danh sach da nhap la: ");
	XuatDS(L);	
	
	//Cau 3
	printf("\n Gia tri trung binh cua day la %.2f ",TinhTB(L));
	
	//Cau 4
	printf("\n Nhap vi tri can xoa trong danh sach k = "); scanf("%d",&k);
	//Xoa phan tu tai vi tri thu k cua DS L
	XoaPT(k,&L);
    printf("\n Danh sach sau khi xoa phan tu thu %d la: ",k);
	XuatDS(L);
	
	//Cau 5
	printf("\n Nhap phan tu can xen hoac xoa X = "); scanf("%f",&X);	
	Xen_XoaPT(X,&L);
	printf("\n Danh sach sau khi xen hoac xoa phan tu thu %.2f la: ",X);
	XuatDS(L);
	
	//Ket thuc CT
	getch();
	return 0;
}

/*
	Cai dat cac chuong trinh con
*/

//Ham khoi tao DS rong
void MakeNull_List (List *L){
	(*L)=(Node*)malloc(sizeof (Node));
    (*L)->Next= NULL;
}

//Ham xen phan tu X vao vi tri P trong DS L
void Insert_List (ElementType X, Position P, List *L){
	Position T;
	T=(Node*)malloc(sizeof(Node));
	T->Elements=X;
	T->Next=P->Next;
	P->Next=T;
}

//Ham nhap danh sach L co n phan tu
void NhapDS(List *L, int n){
   ElementType X;
   Position P;
   P = *L;
	for (int i=0; i<n; i++){
		printf("\n Nhap phan tu thu %d cua danh sach la: ",i+1);
		scanf("%f",&X);
		Insert_List(X,P,L);
		P = P->Next; 
	}
}	

//Ham lay phan tu tai vi tri thu P cua DS L
ElementType Retrieve (Position P, List L){
   if (P->Next !=NULL)    
      return (P->Next->Elements);
}

//Ham in cac phan tu cua DS L
void XuatDS(List L){
   Position P = L;
   while (P->Next!=NULL){
	   printf("%.2f ",Retrieve(P,L));
	   P = P->Next;
   }
   printf("\n");   
}

//Ham tinh gia tri trung binh cua cac phan tu trong DS L
float TinhTB(List L){
   ElementType S = 0;	
   Position P = L;
   int Dem = 0;
   while (P->Next!=NULL){
	   S = S + Retrieve(P,L);
	   Dem++;
	   P = P->Next;
   }
   return (S/Dem);
}

//Ham xoa phan tu tai vi tri P trong DS L
void Delete_List (Position P, List *L){
	Position Temp;
  	if (P->Next!=NULL){ 
 		Temp=P->Next;
   		P->Next=Temp->Next; 
		free(Temp); 	
	}
}

//Ham Xoa phan tu thu k trong DS L
void XoaPT (int k, List *L){
	int Dem = 0;
	Position P = *L;
	while((P->Next !=NULL) && (Dem<k-1)){
		Dem++;
		P = P->Next;
	}
	if(P->Next !=NULL)
	   Delete_List (P,L);
	printf("\n Danh sach khong du %d phan tu !!!",k);   
}

//Ham xac dinh vi tri cua phan tu dau DS
Position First (List L){
	return L;
}

//Ham xac dinh vi tri cua phan tu X trong DS L
Position Locate (ElementType X, List L){
   Position P;
	int Found = 0;
	P = First(L);
	while ((P->Next != NULL) && (Found == 0))
		if (Retrieve(P,L)== X) 
			Found = 1;
		else 
			P = P->Next;
          if (Found == 1)   
		     return P;
          else     
		     return  NULL;    
}

//Ham xen hoac xoa phan tu X neu X khong co/Co trong DS
void Xen_XoaPT(ElementType X, List *L){
	Position P;
	//Tim vi tri cua phan tu X trong DS L
	P = Locate(X, *L);
	if (P!=NULL) //Co X trong DS
	   //Xoa Phan tu X
	   Delete_List (P,L);
	else
	   //Khong co X trong DS
	   Insert_List(X,First(*L),L);
}
