#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define TMAX 40

typedef struct
{
	char character[TMAX];
	char name[TMAX];
} Item;

void print_item_array(Item items[], int size);
int compare_items(const void* first, const void* second);


const Item* binary_search(const Item items[], const int size, const char name[TMAX]);


int main()
{
	Item items[] = {
		{"Iron Man", "Tony Stark"},
		{"Thor","Thor Odinson"},
		{"Ant-Man","Hank Pyn"},
		{"Wasp","Janet van Dyne"},
		{"Hulk","Bruce Banner"},
		{"Captin America", "Steve Rogers"},
		{"Scarlet Witch", "Wanda Maximoff"},
		{"Black Widow", "Natasha Romanoff"},
		{"Dr. Strange", "Stephen Strange"},
		{"Daredevil","Matthew Murdock"},
		{"Punisher", "Frank Castle"},
		{"Batman", "Bruce Wayne"}
	};
	
	int n = sizeof(items) / sizeof(items[0]);		// 배열 개수 파악

	print_item_array(items, n);

	printf("\n\n");
	qsort(items, n, sizeof(Item), compare_items);

	print_item_array(items, n);

	while (1)
	{
		char key[TMAX] = "";
		printf("Input key >> ");

		fgets(key, TMAX, stdin);
		if ((strlen(key) > 0) && (key[strlen(key) - 1] == '\n'))
			key[strlen(key) - 1] = '\0';

		if (strcmp(key, "exit") == 0)
			break;

		const Item* found = binary_search(items, n, key);

		if (found == NULL)
			printf("Not in the list\n\n");
		else
			printf("%s is %s\n\n", found->character, found->name);

	}

	return 0;
}


void print_item_array(Item items[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%-10s (%s)\n", items[i].character, items[i].name);
	}
	printf("\n");
}

int compare_items(const void* first, const void* second)
{
	Item* v1 = ((Item*)first)->character;
	Item* v2 = ((Item*)second)->character;

	if (strcmp(v1, v2) > 0)
		return 1;
	else if (strcmp(v1, v2) < 0)
		return -1;
	else
		return 0;
}


const Item* binary_search(const Item items[], const int size, const char name[TMAX])
{
	int first = 0;
	int last = size - 1;
	int middle;
	int result;

	while (1)
	{
		middle = (first + last) / 2;

		// 비교 결과에 따라 탐색구간 변경
		result = strcmp(items[middle].character, name);

		if (result == 0)
			return &items[middle];
		else if (result > 0)
			last = middle - 1;
		else
			first = middle + 1;


		if (first > last)
			break;

	}
	return NULL;
}
