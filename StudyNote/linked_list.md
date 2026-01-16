# 鏈結串列 (Linked List)
***
## 串列基礎 (What & Why)

* ### 串列是什麼 (What)?
    - 是一種 **線性資料結構 (Linear Data Structure)**，由一系列不連續的記憶體空間組成。
    - 透過 **指標 (Pointer)** 將節點串連起來。每個 **節點 (Node)** 包含：
        1. **資料 (Data)**：實際存放的資訊。
        2. **指標 (Next)**：指向下一個節點的連結。
    

* ### 什麼時候會用到 (When)?
    - 當資料數量不固定，且需要 **頻繁插入或刪除** 元素時。

* ### 為什麼要用串列 (Why)?
    - **動態記憶體配置**：不需要預先分配大小，隨時可以新增節點。
    - **高效增刪**：在已知位置進行插入或刪除時，不需要移動其他元素，只需修改指標。

## 串列的使用方式與類型 (How)

* ### 節點示意圖
    ```c
    [Data | Next] -> [Data | Next] -> [Data | Next] -> NULL
    ```
    - **頭節點 (Head)**：串列的第一個入口。
    - **尾節點 (Tail)**：最後一個節點，其 `Next` 指向 `NULL`。

* ### 實作方式 (C 範例)
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    struct Node {
        int data;
        struct Node* next;
    };

    int main() {
        // 建立動態節點
        struct Node* head = (struct Node*)malloc(sizeof(struct Node));
        head->data = 1;
        head->next = NULL;
        
        // 釋放記憶體
        free(head);
        return 0;
    }
    ```

## 陣列 (Array) vs 鏈結串列 (Linked List) 比較

| 特性 | 陣列 (Array) | 鏈結串列 (Linked List) |
| :--- | :--- | :--- |
| **記憶體配置** | 連續記憶體 | 不連續記憶體，指標串連 |
| **元素存取** | $O(1)$ 隨機存取 | $O(n)$ 需從頭遍歷 |
| **插入/刪除** | $O(n)$ 需搬移元素 | $O(1)$ 僅需改指標 (已知位置下) |
| **記憶體效率** | 可能浪費空間 (預留) | 精確使用，但需額外指標空間 |
| **快取效率** | 高 (連續記憶體) | 低 (節點分散) |
| **應用場景** | 頻繁讀取、已知數量 | 頻繁增刪、數量不固定 |

***
## 鏈結串列時間複雜度

假設串列中有 $n$ 個節點：

| 操作 (Operation) | Singly Linked List | Doubly Linked List | 說明 |
| :--- | :--- | :--- | :--- |
| **存取 / 讀取** | $O(n)$ | $O(n)$ | 必須從 Head 依序查找 |
| **更新元素** | $O(n)$ | $O(n)$ | 尋找節點需 $O(n)$ |
| **搜尋 (Search)** | $O(n)$ | $O(n)$ | 線性搜尋 |
| **插入 (Insert)** | $O(1)$ | $O(1)$ | 已知位置下，修改指標即可 |
| **刪除 (Delete)** | $O(1)$ | $O(1)$ | 單向需前一節點，雙向可直接刪除 |
| **遍歷 (Traverse)** | $O(n)$ | $O(n)$ | 訪問所有節點 |

***
## 結論
* **Linked List** 解決了 Array 在**中間增刪元素**時的高昂代價，但犧牲了**存取速度**。
    - **插入與刪除**：只需修改 `Next` 或 `Prev` 指標的方向，不用像 Array 搬家。
    - **走訪 (Traversal)**：是鏈結串列唯一的搜尋途徑，無法像 Array 使用二分搜尋。
    - **記憶體管理**：開發者必須手動處理 `malloc` 與 `free`，否則會產生 Memory Leak。
