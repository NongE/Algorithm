#include <stdio.h>

int H[100];
int n; // 크기 입력

void downHeap(int num);
void buildHeap(int num) 
{
	if (num > n)
		return;
	else
	{
		buildHeap(2 * num);
		buildHeap(2 * num + 1);
		downHeap(num);
	}
}

void downHeap(int num)
{
	int temp;

	while (1)
	{
		if ((num * 2) == n)
		{
			if (H[num] < H[2 * num])
			{
				temp = H[num];
				H[num] = H[2 * num];
				H[2 * num] = temp;
				num = num * 2;
			}
			else
			{
				break;
			}
		}
		else if ((num * 2) + 1 <= n)
		{
			if (H[2 * num] < H[2 * num + 1])
			{
				if (H[num] < H[2 * num + 1])
				{
					temp = H[num];
					H[num] = H[2 * num + 1];
					H[2 * num + 1] = temp;
					num = num * 2 + 1;
				}
				else
					break;
			}
			else
			{
				if (H[num] < H[2 * num])
				{
					temp = H[num];
					H[num] = H[2 * num];
					H[2 * num] = temp;
					num = num * 2;
				}
				else
				{
					break;
				}
			}
		}
		else
			break;
	}
}

void printHeap()
{
	int i;

	for (i = 1; i <= n; i++)
	{
		printf(" %d", H[i]);
	}
	printf("\n");

}

int main()

{
	int i, j, k;
	scanf("%d",&n); // 배열 크기 입력받기
	getchar();

	for (i = 1; i <= n; i++)
	{

		scanf("%d",&H[i]); // 크기 만큼 숫자 입력
		getchar();
	}

	buildHeap(1);
	printHeap();


	return 0;
}