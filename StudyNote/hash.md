# Hash (雜湊)

---

## 關於 Hash

### Hash 是甚麼 (What)?
* 是一種資料結構，儲存 **Key-Value (鍵值對)** 配對的集合。
* **Key-Value**: 就像字典，透過「關鍵字 (Key)」快速找到「定義內容 (Value)」。
* **定義**: 透過 **Hash Function (雜湊函數)** 計算出一個索引值 (Index)，並將資料存入陣列中對應的 Bucket。


### Hash 什麼情況會用到 (When)?
* **加密 (Encryption)**：將原始資料轉為固定長度的編碼。
* **快速查找**：資料庫索引、快取機制 (Cache)。
* **唯一性檢驗**：檢查檔案是否被修改（如 MD5, SHA）。

### Hash 要怎麼運用 (How)?
* **Hash function 的設計**:
    1. 好的函數關乎數據的 **分佈均勻性** 與 **計算效率**。
    2. **m 值 (Table 大小)**：通常設為 **質數**，能有效減少衝突 (Collision)。
* **衝突 (Collision) 的處理**:
    1. **Chaining (鏈結法)**：使用 Linked List 儲存衝突資料。
    2. **Open Addressing (開放定址法)**：在陣列中找下一個空位。

### Hash 的優缺點 (Pros/Cons)
* **優點 (Pros)**:
    - **查找速度極快**：平均情況為 $O(1)$。
    - 適合大數據量的快速過濾。
* **缺點 (Cons)**:
    - **衝突 (Collision)**：處理衝突會導致性能下降（最差至 $O(N)$）。
    - **空間浪費**：為了減少衝突，通常會預留較大的空間。

---

## Time Complexity (時間複雜度)

### 1. Chaining (鏈結法)
※ 負載因子 (Load Factor) $\alpha = \frac{N}{M}$

| 操作 (Operation) | 最佳 (Best) | 平均 (Average) | 最差 (Worst) |
| :--- | :--- | :--- | :--- |
| **Insertion** | $O(1)$ | $O(1+\alpha)$ | $O(N)$ |
| **Search** | $O(1)$ | $O(1+\alpha)$ | $O(N)$ |
| **Deletion** | $O(1)$ | $O(1+\alpha)$ | $O(N)$ |

### 2. Open Addressing (開放定址法)

| 操作 (Operation) | 最佳 (Best) | 最差 (Worst) |
| :--- | :--- | :--- |
| **Insertion** | $O(1)$ | $O(N)$ |
| **Search** | $O(1)$ | $O(N)$ |
| **Deletion** | $O(1)$ | $O(N)$ |

---

## 運作流程 (Operation)

### 基本流程
* `Key` -> **Hash Function** -> `Index` -> `Value`

### 常用 Hash Function 實作方式
1. **Division method (除法)**:
   $$h(k) = k \bmod m$$
2. **Multiplication method (乘法)**:
   $$h(k) = \lfloor m (k A \bmod 1) \rfloor$$ (通常 $A \approx 0.618$)
3. **Folding method (摺疊法)**:
   將 Key 分段加總，例如 $k = 123456 \Rightarrow (123 + 456) \bmod m$。

### 衝突解決 (Collision Resolution)

#### A. Chaining (鏈結法)
* **原理**: `Array` + `Linked List`。當 Index 相同時，將資料串在該位置的節點後。

* **優點**: 實作動態簡單，不需擔心 Table 填滿。
* **缺點**: 指標管理複雜，且有額外記憶體開銷 (Memory Overhead)。

#### B. Open Addressing (開放定址法)
當發生衝突時，依規則尋找下一個空的 Slot。
1. **Linear Probing (線性探測)**:
   - 公式: $index = (h(k)+i) \bmod m$
   - 缺點: **Primary Clustering** (容易形成大片連續佔用空間)。
2. **Quadratic Probing (平方探測)**:
   - 公式: $index = (h(k) + C_1 \cdot i^2 + C_2 \cdot i) \bmod m$
   - 缺點: **Secondary Clustering**。
3. **Double Hashing (雙重雜湊)**:
   - 公式: $index = (h_1(k) + i \cdot h_2(k)) \bmod m$
   - 優點: 分佈最均勻。

---

## 抽象資料型別 (ADT)

* `Create(D, m)`: 建立大小為 m 的雜湊表 D。
* `Insert(D, k, v)`: 將鍵 k 與值 v 插入表 D。
* `Search(D, k)`: 在表 D 中尋找鍵 k 並回傳對應的值。
* `Delete(D, k)`: 從表 D 中刪除鍵 k 的內容。

---

## 比較 (Static vs Dynamic Hashing)

| 特性 (Feature) | 靜態雜湊 (Static) | 動態雜湊 (Dynamic) |
| :--- | :--- | :--- |
| **大小 (Size)** | 固定 (Fixed) | 可變 (Dynamic) |
| **負載因子** | 隨資料增加效率降低 | 透過 Rehashing 維持效率 |
| **實作難度** | 簡單 | 複雜 |
| **適用場景** | 資料量固定 | 資料量變動劇烈 |
