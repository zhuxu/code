#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char num_str[126];
    int  num;
    struct node *next;
};

int str_mul(char num_buffer[], char num_input[], char num_ans[]);
int str_to_num(char buffer[]);
struct node * sll_reverse(struct node *head);

int main(void)
{
    char buffer[7] = {0};
    int count;
    int point_num = 0;
    char num_ans[126];

    struct node *phead = NULL;

    while (scanf("%s %d",buffer,&count) == 2){
        buffer[6] = '\0';
        point_num = str_to_num(buffer);
	struct node *ptemp = (struct node *)malloc(sizeof(struct node));
	strncpy(ptemp->num_str,buffer,strlen(buffer) + 1);
	ptemp->num = point_num * count;
	while (count > 1){
	    str_mul(buffer,ptemp->num_str,num_ans);
	    count--;
	}
	ptemp->next = phead;
	phead = ptemp;
    }

    if (phead->next != NULL)
        phead = sll_reverse(phead);

    struct node *p_index = phead;
    int flag;
    int sum_bit = 0;
    while (phead != NULL){
        sum_bit = strlen(phead->num_str);
	flag = 0;
        for (count = 125; count > 0; count--){
	    if ((phead->num_str[count] - 48) > 0){
		if (count < sum_bit - phead->num){
		    phead->num_str[sum_bit - phead->num] = '\0';
		    break;
		}
	        phead->num_str[count+1] = '\0';
	        break;
	    }
	}
	for (count = 0; phead->num_str[count] != '\0'; count++){
	    if ((phead->num_str[count] > 48) || (count == (sum_bit - phead->num))){
	        flag = 1;
	    }
	    if (count == sum_bit - phead->num)
	        putchar('.');
	    if (flag == 1)
	        putchar(phead->num_str[count]);
	}
	putchar('\n');

	phead = phead->next;
    }

    phead = p_index;
    while (phead != NULL){
        p_index = phead;
	phead = phead->next;
	p_index->next = NULL;
	free(p_index);
    }

    return 0;
}

struct node * sll_reverse(struct node *head)
{   /* 原地逆转单链表 */
    if (head == NULL)
        return head;
    struct node *upper;
    struct node *later;
    upper = head;
    later = head->next;
    upper->next = NULL;
    head = later;
    while (head->next != NULL){
        head = head->next;
        later->next = upper;
        upper = later;
        later = head;
    }
    later->next = upper;

    return head;
}


/*计算乘法*/
int str_mul(char num_buffer[], char num_input[], char num_ans[])
{
    int i, j = 0 ;
    int j_temp = 0;
    int k = strlen(num_buffer) + strlen(num_input);
    int k_temp = k - 1;

    num_ans[k] = '\0';
    while (--k >= 0){
        num_ans[k] = '0';
    }
    j = strlen(num_input);
    j_temp = j - 1;
    for (i = 4; i >= 0; i--){
        for (j = j_temp; j >= 0; j--){
	    num_ans[i+j+1] += ((num_input[j] - 48)*(num_buffer[i] - 48)) % 10;
	    num_ans[i+j] += ((num_input[j] - 48)*(num_buffer[i] - 48)) / 10;
	}
	/*处理进位*/
	for (k = k_temp; k > 0; k--){
	    if ((num_ans[k] - 48) >= 10){
	        num_ans[k - 1] += (num_ans[k] - 48) / 10;
		num_ans[k] = (num_ans[k] -48) % 10 + 48;
	    }
	}
    }
    strncpy(num_input,num_ans,strlen(num_ans) + 1);

    return 0;
}

/*返回值为小数点后面的位数*/
int str_to_num(char buffer[])
{
    int bit_num = 0;

    while (*buffer++ != '.')
        ;
    while (*buffer != '\0'){
        *(buffer-1) = *buffer; 
        buffer++;
	bit_num++;
    }
    *(buffer-1) = '\0';

    return bit_num;
}
