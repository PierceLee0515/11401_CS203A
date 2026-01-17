# Stack (堆疊)

***

## 什麼是 *Stack*? (What is Stack?)

* ### 什麼 (What)?
    - 它是一種線性資料結構，遵循 **LIFO (Last-In-First-Out, 後進先出)** 原則。
    - 也就是最後進入的元素會最先被取出。
    

* ### 哪裡用 (Where)?
    - **REDO / UNDO 功能**：記錄操作步驟以便回退。
    - **函數呼叫堆疊 (Function Call Stack)**：系統管理遞迴或函數執行順序。
    - **運算式轉換**：例如將中序運算式 (Infix) 轉為後序 (Postfix)。

* ### 怎麼做 (How)?
    - **Stack (Array-based)**：使用連續記憶體實作，存取快但大小受限。
    - **Stack (Linked-list-based)**：使用指標串連，動態配置空間，不受大小限制。

---

## 如何用不同的資料類型實作 Stack? (Implementation)

* ### Stack (Array-based)

    - **初始化 (Initialize)**
        ```c
        int the_Array_num = 10;
        int arr[the_Array_num];
        int top = -1; // 初始化為 -1 代表堆疊為空
        ```

    - **推入 (Push)**
        ```c
        int insert_value = 100;
        // 檢查是否溢位 (Overflow)
        if (top < the_Array_num - 1) {
            arr[++top] = insert_value;
        }
        ```

    - **彈出 (Pop)**
        ```c
        int value;
        // 檢查是否下溢 (Underflow)
        if (top != -1) {
            value = arr[top--];
        }
        ```

    - **邊界情況 (Edge Case)**
        1. 必須檢查 `Overflow` (當 `top == the_Array_num - 1`)。
        2. 必須檢查 `Underflow` (當 `top == -1`)。
        3. 若使用靜態陣列 (Static Array)，一旦宣告後大小即固定，無法動態擴張。

* ### Stack (Linked-List-based)

    - **初始化 (Initialization)**
        ```cpp
        struct Node {
            int val;
            Node* next;
        };
        Node* top = NULL; // 頂端指標初始化為空
        ```

    - **推入 (Push)**
        ```cpp
        Node* newNode = new Node();
        newNode->val = insert_value;
        newNode->next = top; // 新節點指向原本的頂端
        top = newNode;       // 頂端指標移至新節點
        ```

    - **彈出 (Pop)**
        ```cpp
        if (top != NULL) {
            Node* temp = top;
            int value = temp->val;
            top = top->next; // 頂端指向下一個節點
            delete temp;     // 釋放記憶體避免 Leak
        }
        ```

    - **邊界情況 (Edge Case)**
        1. **記憶體管理**：每次 `pop` 後必須手動釋放記憶體。
        2. **空值判斷**：在執行 `pop` 或 `peek` 操作前，必須確保 `top != NULL`。

---

## 抽象資料型別 (Stack ADT)

* `push(element)`: 將元素壓入堆疊最上方。
* `pop()`: 移除並回傳堆疊最上方的元素。
* `peek() / top()`: 取得堆疊最上方元素的值，但不移除。
* `isEmpty()`: 檢查堆疊是否為空。
* `isFull()`: 檢查堆疊是否已達容量上限 (僅限 Array-based)。

---

## 總結比較

| 特性 | Array-based Stack | Linked-List-based Stack |
| :--- | :--- | :--- |
| **時間複雜度** | Push/Pop 皆為 $O(1)$ | Push/Pop 皆為 $O(1)$ |
| **空間效率** | 預先配置，可能浪費空間 | 隨需配置，但每個節點需額外指標空間 |
| **大小限制** | 受限於初始宣告大小 | 僅受限於系統記憶體 |

---

## Stack vs Queue 比較

| 項目 | Stack | Queue |
|------|-------|-------|
| 存取順序 | LIFO（後進先出） | FIFO（先進先出） |
| 插入位置 | Top | Rear |
| 刪除位置 | Top | Front |
| 常見應用 | 函式呼叫、Undo | 排程、排隊系統 |
