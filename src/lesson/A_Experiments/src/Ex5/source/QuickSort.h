#ifndef QUICKSORT_H_
#define QUICKSORT_H_

void swap(int &x, int &y) {
	int t = x;
	x = y;
	y = t;
}

void quick_sort(int *array, int left, int right) {
	int i = left, j = right, mid = array[(left + right) / 2];
	do {
		while (i < right && array[i] < mid)
			i++;
		while (j > left && array[j] > mid)
			j--;
		if (i <= j) {
			swap(array[i], array[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < right)
		quick_sort(array, i, right);
	if (j > left)
		quick_sort(array, left, j);
}

#endif /* QUICKSORT_H_ */
