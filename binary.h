#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Node tree
struct node {
    char nama[50];
    int kondisi;
    struct node* left;
    struct node* right;
};

// Inisiasi node baru
struct node* newNode(char nama[50],int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
 
    node->kondisi = data;
 	strcpy(node->nama,nama);
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Menambahkan node baru ke tree
struct node* insert(struct node* node,char nama[50], int kondisi)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(nama,kondisi);
	// Kalo abjad lebih besar, taro kanan tree
 	if (strcmpi(nama, node->nama) > 0) {
        node->left = insert(node->left,nama, kondisi);
    }
    // Kalo abjad lebih kecil, taro kiri tree
    else
        node->right = insert(node->right,nama, kondisi);
    return node;
}

// Mencari node dengan nilai terkecil
struct node* minValueNode(struct node* node)
{
	// Dalam tree, node terkecil ada di sebelah kiri subtree
    struct node* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

// Menghapus node secara rekursif
struct node* deleteNode(struct node* root,char nama[50],char b_nama[50], int kondisi)
{
    if (root == NULL)
        return root;
    if (strcmpi(nama, root->nama) > 0)
        root->left = deleteNode(root->left,nama,b_nama, kondisi);
    else if (strcmpi(nama, root->nama) < 0)
        root->right = deleteNode(root->right,nama,b_nama, kondisi);
    // Sampai kode ini, berarti node target ketemu
	else {
    	printf("%s",root->nama);
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->kondisi = temp->kondisi;
        strcpy(root->nama,temp->nama);
        root->right = deleteNode(root->right,nama,b_nama,kondisi);
    }
    return root;
}


// Print isi tree dari yang terkecil
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        switch(root->kondisi){				//dengan menggunakan switch case dapat menampilkan 3 macam kondisi pasien
			case 1:
				printf("(Sehat)\t\t\t%s\n", root->nama);
				break;
			case 2:
				printf("(Positif COVID-19)\t%s\n", root->nama);
				break;
			case 3:
				printf("(Meninggal)\t\t%s\n", root->nama);
				break;
			default:
				printf("\nInvalid input in patient named %s \n",root->nama);
        		printf("Please enter the correct input via the data edit menu!\n\n");
		}
        inorder(root->right);
    }
}

// Mencari node secara rekursif
void searching(struct node* root,char nama[50])
{
	int found=0;
    if (root != NULL) {
        searching(root->left,nama);
        if(strcmp(root->nama,nama)==0){
	        found=1;
			switch(root->kondisi){				//dengan menggunakan switch case dapat menampilkan 3 macam kondisi pasien
				case 1:
					printf("(Sehat)\t\t\t%s\n", root->nama);
					break;
				case 2:
					printf("(Positif COVID-19)\t%s\n", root->nama);
					break;
				case 3:
					printf("(Meninggal)\t\t%s\n", root->nama);
					break;
				default:
					printf("\nInvalid input in patient named %s \n",root->nama);
	        		printf("Please enter the correct input via the data edit menu!\n\n");
			}
		}
        searching(root->right,nama);
    }
}

