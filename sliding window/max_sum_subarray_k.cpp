
int maxSubarraySum(vector<int>& arr, int k) {

    int n = arr.size();

    int left = 0;
    int right = k - 1;

    int sum = 0;

    for (int i = left; i <= right; i++) {
        sum += arr[i];
    }

    int maxSum = sum;

    while (right < n - 1) {

        sum -= arr[left];
        left++;

        right++;
        sum += arr[right];

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}