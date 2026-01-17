# Tree (樹)
***
## 關於樹 (About Tree)

- **什麼是樹 (What is a Tree)?**
    * 它是一種 **非線性 (non-linear)** 的階層式 **資料結構**。
    * 由節點 (Node) 與邊 (Edge) 組成，且不包含任何迴圈 (Cycle)。

- **樹會用在哪裡 (Where are trees used)?**
    * 電腦的 **檔案系統 (File systems)**。
    * **家族譜 (Family Trees)**。
    * **DOM 結構** (網頁設計)。

- **樹有哪些類型 (What types of trees are there)?**
    * 常見的包括：`二元樹 (Binary Tree)`、`二元搜尋樹 (BST)`、`平衡樹 (Balanced Tree, 如 AVL)`。

- **高度 (Height) 與 深度 (Depth) 的區別?**
    * **高度 (Height)**：從 **目標節點 → 最深葉子** 的邊數（這棵樹總共有幾層）。
    * **深度 (Depth)**：從 **根節點 → 目標節點** 的邊數（該節點位在第幾層）。
    

## 樹的組成 (Tree's Composition)

| 🌲 術語 (Term) | 💡 定義 (Definition) |
| :--- | :--- |
| **兄弟節點 (Sibling)** | 擁有相同父節點的節點。 |
| **父子節點 (Parent/Child)** | **Parent** 是直接連接到下一層的節點；**Child** 則是連接回上一層的節點。 |
| **分枝度 (Degree)** | 一個節點擁有的子節點數量。 |
| **根節點 (Root)** | 樹的最頂端節點，沒有父節點。 |
| **葉節點 (Leaf)** | 沒有任何子節點的末端節點，又稱外部節點 (External Node)。 |
| **邊 (Edge)** | 連接兩個節點之間的連結。 |

## 樹的遍歷 (Tree's Traversal)

- **DFT (深度優先遍歷):**
    * 遵循 `深度優先` 策略，會先往某個子樹的最深處走。
    * 包含三種方式：
        * **A (後序 Postorder):** `左 -> 右 -> 根`。常用於 **刪除節點** 或 **釋放記憶體**。
        * **B (前序 Preorder):** `根 -> 左 -> 右`。常用於 **複製** 完整樹結構。
        * **C (中序 Inorder):** `左 -> 根 -> 右`。在 BST 中可用於 **排序**。
        

- **BFT (廣度優先遍歷):**
    * 又稱層序遍歷 (Level-order Traversal)，利用 **佇列 (Queue)** 一層一層訪問節點。

## 樹的種類 (Types of Trees)

### 1. 二元樹 (Binary Tree)
* **定義:** 每個節點最多只能有兩個子節點 (0, 1, 或 2)。
* **特殊類型**:
    * **Full Binary Tree (完滿二元樹)**: 每個節點只有 0 或 2 個子節點。
    * **Complete Binary Tree (完全二元樹)**: 除了最後一層外皆填滿，且節點皆靠左對齊。
    * **Perfect Binary Tree (完美二元樹)**: 所有層皆填滿，所有葉子深度相同。
    * **Degenerate Binary Tree (退化二元樹)**: 每個父節點僅有一個子節點，形同 Linked List。
    

### 2. 二元搜尋樹 (BST)
* **定義:** 繼承自二元樹，並遵循以下排序規則：
    $$\text{左子節點} < \text{父節點} < \text{右子節點}$$
* **特性:**
    * 左子樹的所有節點值必小於父節點。
    * 右子樹的所有節點值必大於父節點。
    * 此規則遞迴套用於所有子樹。

### 3. 平衡樹 (Balanced Tree)
* **定義:** 確保左右子樹的 **高度差 (Height difference)** 最小化。
* **原因:** * 若樹不平衡，可能會發生「傾斜」，導致操作效率從 $O(\log n)$ 退化為 $O(n)$。

## 抽象資料型別 (ADT)
- `Create()`: 建立一個樹結構。
- `Lchild()`: 回傳左子節點。
- `Rchild()`: 回傳右子節點。
- `IsEmpty()`: 檢查是否為空樹。

