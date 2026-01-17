# 隊列 (Queue)

---

## 關於隊列 (About Queue)

### 什麼是隊列 (What is Queue)?
* 一種 **線性資料結構**，遵循 **FIFO (First-In-First-Out, 先進先出)** 的原則。
* 想像排隊買票，第一個排隊的人會第一個買到票並離開。
[Image of Queue data structure showing Enqueue and Dequeue operations at front and rear]

### 什麼時候會用到 (Where to use Queue)?
* **工作排程 (Task scheduling)**：例如印表機的待列印文件。
* **緩衝區 (Buffering)**：用於處理 I/O 資料串流，平衡速度不一的情況。

### 如何實作 (How to implement Queue)?
* **陣列 (Array)** / **鏈結串列 (Linked List)**

---

## 實作方式 (Implementation)

### 1. 基於陣列的隊列 (Array-based Queue)

**需要變數:**
* **Front** (頭指標)、**Rear** (尾指標)、**Array Size** (陣列大小)、**Current** (目前元素個數)

**操作邏輯 (通常使用環狀陣列 Circular Array):**
* **Enqueue (入隊):** `Array[(rear + 1) % array_size] = value`
* **Dequeue (出隊):** `Array[(front + 1) % array_size] = value`

**邊界情況處理 (Edge Cases):**

* **隊列已滿 (Overflow):** 當空間用盡且嘗試放入新元素時：
    ```c
    if ((rear + 1) % array_size == front) {
        printf("Queue Full\n");
        return;
    }
    ```

* **隊列為空 (Underflow):** 當隊列沒有元素且嘗試取出時：
    ```c
    if (front == rear) {
        printf("Queue Empty\n");
        return;
    }
    ```

### 2. 基於鏈結串列的隊列 (Linked List-based Queue)

**需要變數:**
* **Front** (指向第一個節點)、**Rear** (指向最後一個節點)

**初始化 (Initialization):**
```c
// 先宣告一個 Linked List 節點結構
front = head; // 使 front 和 rear 都指向同一個起始位置 (dummy node)
rear = head;
