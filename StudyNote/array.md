# Linked List (鏈結串列)
***
## 串列基礎 (What & Why)

* ### 串列是什麼 (What)?
    - 是一種儲存資料的方式，將資料存在**不連續的記憶體 (Non-contiguous Memory)** 中。
    - 每個節點 (Node) 包含兩個部分：**資料 (Data)** 與 **指標 (Next Pointer)**。
    - A linear data structure where elements are not stored at contiguous memory locations; instead, they are linked using pointers.

* ### 什麼時候會用到 (When)?
    - 當你的資料量會頻繁變動（增加或減少），且你無法預期到底需要多少空間時。

* ### 為什麼要用串列 (Why)?
    - **動態配置 (Dynamic Allocation)**：不需要事先宣告大小，記憶體是有需要才申請，不會浪費空間。
    - **插入/刪除極快**：不需要搬移大量元素，只要更改指標 (Pointer) 的指向即可。

## 串列的使用方式與類型 (How)

* ### 要怎麼用 (How)?
    - 需要先定義一個結構 (Structure) 來表示節點，並手動透過指標連接它們。
    - 在 C 語言中，我們通常使用 `struct` 來定義：

        ```c
        #include <stdio.h>
        #include <stdlib.h>

        // 定義節點結構
        struct Node {
            int data;           // 存放資料
            struct Node* next;  // 指向下一個節點的指標
        };

        int main() {
            // 建立一個簡單的節點
            struct Node* head = (struct Node*)malloc(sizeof(struct Node));
            head->data = 10;
            head->next = NULL;

            // 記得釋放記憶體
            free(head);
            return 0;
        }
        ```

* ### 常見的串列類型：
    - **Singly Linked List (單向串列)**: 每個節點只知道下一個在哪裡。
    - **Doubly Linked List (雙向串列)**: 每個節點都有 `prev` 與 `next` 指標，可雙向走訪。
    - **Circular Linked List (環狀串列)**: 最後一個節點指向頭節點，形成閉環。

## 串列的整體優缺點

* ### 優點 (Strengths)
    - **動態調整大小**: 完全沒有大小限制（只要記憶體夠）。
    - **插入與刪除節點**: 在已知位置下，只需修改指標指向，時間複雜度為 $O(1)$。

* ### 缺點 (Weaknesses)
    - **無法隨機存取 (Random Access)**: 不能像 Array 用 `index` 直接定位，必須從頭走訪。
    - **額外記憶體開銷**: 每個節點都要額外空間存放指標。
    - **對快取不友善**: 記憶體不連續，CPU Cache Hit Rate 較低。

***
## 串列的正式使用

- ### Step 1: 建立與串接節點
    * **目的:** 撰寫一個函式自動分配記憶體並初始化節點。

    ```c
    struct Node* createNode(int val) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) return NULL; // 檢查分配是否成功
        newNode->data = val;
        newNode->next = NULL;
        return newNode;
    }
    ```

- ### Step 2: 走訪串列 (Traversal)
    * **目的:** 使用 `while` 迴圈逐一訪問每個節點直到末尾。

    ```c
    void printList(struct Node* head) {
        struct Node* current = head;
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
    ```

---

## 串列 ADT 與演算法

### 1. 抽象資料類型 (Linked List ADT)
* **Insert(val, pos):** 將值插入到指定位置。
* **Delete(val):** 刪除含有特定值的節點。
* **Search(target):** 在串列中尋找特定目標。
* **Length():** 回傳串列中的節點總數。

### 2. 重要演算法：反轉串列 (Reverse)

* 這是最經典的串列演算法，透過三個指標進行轉向。

    ```c
    struct Node* reverse(struct Node* head) {
        struct Node *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL) {
            next = curr->next; // 暫存下一個
            curr->next = prev; // 核心：轉向
            prev = curr;       // 指標後移
            curr = next;
        }
        return prev; // 新的頭節點
    }
    ```

### 3. 時間複雜度比較 (vs. Array)

| Operation (操作)     | Linked List (串列) | Array (陣列) | Notes (備註)                                    |
| :------------------- | :----------------- | :----------- | :---------------------------------------------- |
| **Access** (存取)    | $O(N)$             | $O(1)$       | 串列須走訪；陣列可用索引                       |
| **Insert** (插入)    | $O(1)$             | $O(N)$       | 串列只需改指標；陣列需移動元素                 |
| **Delete** (刪除)    | $O(1)$             | $O(N)$       | 串列只需改指標；陣列需移動元素                 |
| **Search** (搜尋)    | $O(N)$             | $O(N)$       | 陣列排序後可用 Binary Search 優化至 $O(\log N)$ |

***
### 1. Bubble Sort（氣泡排序）
- **原理**：反覆比較相鄰元素，若順序錯誤就交換  
- **特性**：較大的元素會逐步移動到陣列尾端  
- **穩定性**：穩定（Stable）  
- **時間複雜度**：  
  - 最佳情況：O(n)  
  - 平均 / 最差情況：O(n²)  
- **適合情況**：資料量小、教學與概念示範用途  

---

### 2. Selection Sort（選擇排序）
- **原理**：每回合從未排序區中找出最小值，放到正確位置  
- **特性**：比較次數固定、交換次數少  
- **穩定性**：不穩定（Unstable）  
- **時間複雜度**：  
  - 最佳 / 平均 / 最差情況：O(n²)  
- **適合情況**：交換成本較高的情境  

---

### 3. Insertion Sort（插入排序）
- **原理**：將未排序元素插入已排序區的正確位置  
- **特性**：類似整理撲克牌  
- **穩定性**：穩定（Stable）  
- **時間複雜度**：  
  - 最佳情況：O(n)  
  - 平均 / 最差情況：O(n²)  
- **適合情況**：資料接近已排序、小型資料集  
## 結論
* Linked List 是處理**動態資料**的首選，特別是插入刪除頻繁的場景。
    - **指標安全**: 操作時要小心 `NULL` 指標，否則會發生 `Segmentation Fault`。
    - **記憶體釋放**: 使用完畢必須走訪串列並逐一 `free` 節點，否則會造成 Memory Leak。
