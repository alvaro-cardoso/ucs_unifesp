typedef int TKey;

typedef struct{
TKey Key;
}TItem;

typedef struct SCell *TPointer;

typedef struct SCell{
TItem item;
TPointer B4,Nxt;
}TCell;

typedef struct{
int len;
TPointer First,Last;
}TList;


int TList_Test (TList *pList);
int TList_Start (TList *pList);
int TList_Clearspc (TList *pList, TPointer pPointer, TItem *x);
int TList_InsertF (TList *pList, TItem x);
int TList_Print (TList *pList);
int TList_Len (TList *pList);
TPointer TList_Return (TList *pList,int p);

