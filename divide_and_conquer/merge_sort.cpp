#include<iostream>
#include<vector>

using namespace std;

void combine(vector<int>& nums, int i, int j);


void merge_sort(vector<int>& nums, int i, int j) {
	if(j - i <= 0)
		return;
	merge_sort(nums, i,i+(j-i)/2);
	merge_sort(nums, (i+(j-i)/2)+1, j);
	combine(nums, i, j);
	return;
}

void combine(vector<int>& nums, int i, int j) {
	if(j - i <= 0)
		return;
	vector<int> ans;
	int end1 = (i+(j-i)/2)+1;
	int end2 = j+1;
	int lptr = i, rptr = end1;
	while(lptr != end1 && rptr != end2) {
		if(nums[lptr] < nums[rptr]) {
			ans.push_back(nums[lptr]);
			lptr++;
		}
		else {
			ans.push_back(nums[rptr]);
			rptr++;
		}
	}
	if(lptr == end1) {
		while(rptr != end2) {
			ans.push_back(nums[rptr]);
			rptr++;
		}
	}
	else if(rptr == end2) {
		while(lptr != end1) {
			ans.push_back(nums[lptr]);
			lptr++;
		}
	}
	for(int x=i;x<=j;x++)
		nums[x] = ans[x-i];
	return;
} 

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		vector<int> nums;
		cin >> n;
		for(int i=0;i<n;i++) {
			int num;
			cin >> num;
			nums.push_back(num);
		}
		merge_sort(nums, 0, n-1);
		for(int i=0;i<n;i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
