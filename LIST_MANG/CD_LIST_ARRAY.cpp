#include <stdio.h>
#include <conio.h>

// khai bao cau truc danh sach bang mang (*)

#define MaxLength 30 // So phan tu toi da cua danh sach
typedef    float ElementType; // Dinh ngia kieu phan tu theo kieu du lieu so thuc
typedef    int Position; // Dinh nghia kieu vi tri theo kieu so nguyen
// Khai bao mot cau truc cua mot phan tu trong danh sach
typedef   struct{
    ElementType	Elements[MaxLength]; // mang chua cac phan tu cua danh sach
    Position	Last; // Giu do dai danh sach
} List;
// Cac chuong trinh con (*)

// Ham khoi tao rong (1)
void MakeNull_List(List *L){
	L->Last=0;
}

// Ham kiem tra rong (2)
int Empty_List (List L){
	return (L.Last==0);
}

// Ham kiem tra day (3)
int Full_List (List L){
	return (L.Last==MaxLength);
}

//Ham xen phan tu X vao vi tri P trong DS L (4)
void Insert_List (ElementType X, Position P, List *L){
	if(Full_List(*L))
       printf("Danh sach day");
    else
        if((P<1) || (P>L->Last+1))
           printf("Vi tri khong hop le");
       else {   Position Q;
        /*Doi cac phan tu tu vi trí p den cuoi dsách ra sau 1 vi trí*/
      for(Q=L->Last;Q>=P-1;Q--)
           L->Elements[Q]=L->Elements[Q-1];
      L->Elements[P-1]=X; // Xen X
      L->Last++;  // Tang do dai DS L
   }
}

// Ham nhap danh sach vao (5)
void In_List(List *L, int n){
	ElementType X;
	for (int i=0; i<n; i++){
		printf("\n Nhap phan tu thu %d cua danh sach la: ",i+1);
		scanf("%f",&X);
		Insert_List(X,i+1,L);
	}
}

//Ham lay phan tu tai vi tri thu P cua DS L (6)
ElementType Retrieve (Position P, List L){
	return (L.Elements[P-1]);
}

// Ham xuat danh sach da nhap vao (7)
void Out_List(List L){
	for(int i=1; i<=L.Last; i++)
	   printf("%.2f ",Retrieve(i,L));
	printf("\n");   
}

// Ham tinh gia tri trung binh cua day
ElementType TinhTB(List L){
	ElementType S=0;
	for(int i=1;i<=L.Last;i++){
		S=S+Retrieve(i,L);
	}
	return (S/L.Last);
}

//Ham xoa phan tu tai vi tri P trong DS L
void Delete_List (Position P, List *L){
	if (Empty_List(*L))
      printf("Danh sach rong!");
   else
      if ((P<1) || (P>L->Last))
         printf("Vi tri khong hop le");
      else{
         Position Q;
         /*Doi các phan tu tu vi trí p+1 den cuoi ds ra truoc 1 vi tri*/
         for(Q=P;Q<L->Last;Q++)
               L->Elements[Q-1]=L->Elements[Q];
         L->Last--;
     }
}

//Ham Xac dinh vi tri cua phan tu Dau DS
Position First (List L){
	return 1;
}

//Ham Xac dinh vi tri cua phan sau phan tu cuoi cung trong DS
Position EndList (List L){
	return (L.Last+1);
}

//Ham Xac dinh vi tri cua phan lien sau phan tu P trong DS
Position Next (Position P, List L){
	return (P+1);
}

//Ham xac dinh vi tri cua phan tu X trong DS L
Position Locate (ElementType X, List L){
   Position P;
   int Found = 0;
   P = First(L); //vi trí phan tu dau tiên trong DS
    while((P != EndList(L)) && 
              (Found == 0))
         if (Retrieve(P,L) == X) 
             Found = 1;
         else 
             P = Next(P, L);
    return P;
}

//Ham xen hoac xoa phan tu X neu X khong co/Co trong DS
void Xen_XoaPT(ElementType X, List *L){
	Position P;
	//Tim vi tri cua phan tu X trong DS L
	P = Locate(X, *L);
	if (P!=EndList(*L)) //Co X trong DS
	   //Xoa Phan tu X
	   Delete_List (P,L);
	else
	   //Khong co X trong DS
	   Insert_List(X,First(*L),L);   
}

// Chuong trinh chinh (**)
int main(){
	int n,k;
	List L;
	ElementType X;
	Position P;
	// Cau 2
	printf("So phan tu cua danh sach muon nhap vao: ");
	scanf("%d",&n);
	// Khoi tao mot danh sach rong
	MakeNull_List(&L);
	// Nhap danh sach
	printf("\n Nhap cac phan tu cua danh sach L:");
	In_List(&L,n);
	// Xuat danh sach
	printf("\n Danh sach da nhap la: ");
	Out_List(L);
	// Cau 3 tinh gia tri trung binh
	printf("\n Gia tri trung binh cua day la: %.2f",TinhTB(L));
	// Cau 4
	printf("\n Nhap vi tri can xoa trong danh sach k = ");
	scanf("%d",&k);
	//Xoa phan tu tai vi tri thu k cua DS L
	Delete_List (k,&L);
    printf("\n Danh sach sau khi xoa phan tu thu %d la: ",k);
    Out_List(L);
    // Cau 5
    /* nhap vao mot so thuc X khac roi so sanh gia tri trong danh sach xem co hay khong neu co thi xoa ,
	neu khong co thi them x vao trong danh sach
	*/ 
	printf("\n Nhap phan tu can xen hoac xoa X = "); scanf("%f",&X);	
	Xen_XoaPT(X,&L);
	printf("\n Danh sach sau khi xen hoac xoa phan tu thu %.2f la: ",X);
	Out_List(L);
    getch();
    return (0);
}

