#include <bits/stdc++.h>
using namespace std;
/*
最小堆
*/
template <class T> class MinHeap {
private:
	T* mHeap; // data
	int mCapacity;
	int mSize;
	static const int DEFAULT_SIZE = 30;

private:
	// minHeap 向下调整算法
	void filterDown(int start, int end);
	// minHeap 向上调整算法
	void filterUp(int start);

public:
	MinHeap();
	MinHeap(int mCapacity);
	~MinHeap();

	// return the index of data in minHeap
	int getIndex(T data);
	//插入指定data并调整堆结构
	int insert(T data);
	//移除 minHeap 中 指定的data并调整堆结构
	int remove(T data);
};

/*
 * MinHeap构造函数
 */
template <class T> MinHeap<T>::MinHeap() { new (this) MinHeap(DEFAULT_SIZE); }

template <class T> MinHeap<T>::MinHeap(int capcaity) {
	mSize = 0;
	mCapacity = capcaity;
	mHeap = new T mHeap[capcaity];
}

/*
 * MinHeap析构函数
 */
template <class T> MinHeap<T>::~MinHeap() {
	mSize = 0;
	mCapacity = 0;
	delete[] mHeap;
}

/*
 *  获得堆中相应元素索引
 *   返回值：
 *       存在   —— 返回data在堆中的索引
 *       不存在 —— 返回 -1
 */
template <class T> int MinHeap<T>::getIndex(T data) {
	for (int i = 0; i < mSize; ++i)
		if (mHeap[i] == data)
			return i;
	return -1;
}

/*
 * 最小堆的向上调整算法，一般用于插入
 * 注： 当前节点：N    左孩子节点：2N + 1    右孩子节点：2N + 2
 * 参数说明：
 *       start —— 被上调节点的索引，一般为数组中最后一个元素的索引
 */
template <class T> void MinHeap<T>::filterUp(int start) {
	int c = start;       //当前节点下标
	int p = (c - 1) / 2; //父亲节点下标
	T elem = mHeap[c];   //当前节点的元素

	while (c > 0) {
		if (mHeap[p] <= elem)
			break;
		mHeap[c] = mHeap[p];
		c = p;
		p = (p - 1) / 2;
	}
	mHeap[c] = elem;
}

/*
 * 最小堆中插入元素
 * 返回值：
 *   0  —— 插入成功
 *   -1 —— 插入失败
 */
template <class T> int MinHeap<T>::insert(T data) {
	//堆满
	if (mSize == mCapacity)
		return -1;
	mHeap[mSize] = data; //数据先放入堆尾
	filterUp(mSize);     //插入数据，向上调整元素
	mSize++;             //更新堆大小
	return 0;
}

/*
 *  最小堆的向下调整算法，一般用删除
 *  参数说明：
 *       start - 被调整节点下标，一般为0
 *       end -   调整范围，一般到堆末尾，最大为mSize -1
 *
 */
template <class T> void MinHeap<T>::filterDown(int start, int end) {
	int c = start;     //当前节点的下标
	int l = 2 * c + 1; //左子节点下标
	T elem = mHeap[c]; //当前节点对应值

	while (l <= end) {
		// l是左子节点，r是右子节点
		// 两子节点选择较小者（为啥
		if (l < end && mHeap[l] > mHeap[l + 1])
			l++;
		if (elem <= mHeap[l])
			break;
		mHeap[c] = mHeap[l];
		c = l;
		l = l * 2 + 1;
	}
	mHeap[c] = elem;
}

/*
 * 删除堆中的元素
 * 返回值：
 *   0  —— 成功
 *   -1 —— 失败
 */
template <class T> int MinHeap<T>::remove(T data) {
	//堆空不需要删除
	if (mSize == 0)
		return -1;
	int index = getIndex(data);
	//若data在堆中不存在，也不需要删除
	if (index == -1)
		return -1;
	//删除当前节点元素，用堆尾元素递补
	mHeap[index] = mHeap[--mSize];
	filterDown(index, mSize - 1);

	return 0;
}

int main() { return 0; }
