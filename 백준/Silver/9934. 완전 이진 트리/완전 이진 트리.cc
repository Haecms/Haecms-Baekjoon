#include<stdio.h>
#include<vector>
int k, visited[1030], a;
std::vector<std::vector<int>> v[10];

int multiple(int basic, int times) {
	if (times > 0) {
		return basic * multiple(basic, times - 1);
	}
	else return 1;
}

void binaryTree(int startPoint, int endPoint, int times) {
	if (times == k) return;
	if (visited[(startPoint + endPoint) / 2]) {
		v[times].push_back({ visited[(startPoint + endPoint) / 2] });
		binaryTree(startPoint, (endPoint+startPoint) / 2, times + 1);
		binaryTree((endPoint + startPoint) / 2, endPoint, times + 1);
	}
}
int main() {
	scanf("%d", &k);
	for (int i = 1; i < multiple(2,k); i++) {
		scanf("%d", &a);
		visited[i] = a;
	}
	binaryTree(1, multiple(2, k), 0);
	for (int i = 0; i < k; i++) {
		for (auto v2 : v[i]) {
			printf("%d ", v2[0]);
		}
		printf("\n");
	}
}