import random


class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None
    
    #region insert
    def insert(self, value):
        if self.root is None:
            self.root = Node(value)
        else:
            self._insert_recursive(self.root, value)

    def _insert_recursive(self, current_node, value):
        if value < current_node.value:
            if current_node.left is None:
                current_node.left = Node(value)
            else:
                self._insert_recursive(current_node.left, value)
        elif value > current_node.value:
            if current_node.right is None:
                current_node.right = Node(value)
            else:
                self._insert_recursive(current_node.right, value)
        else:
            # Değer zaten ağaçta var, bu durumda bir şey yapmaya gerek yok.
            pass
    #endregion
    
    #region search
    def search(self, value):
        return self._search_recursive(self.root, value)

    def _search_recursive(self, current_node, value):
        if current_node is None or current_node.value == value:
            return current_node
        if value < current_node.value:
            return self._search_recursive(current_node.left, value)
        else:
            return self._search_recursive(current_node.right, value)
    #endregion
    
    #region delete
    def delete(self, value):
        self.root = self._delete_recursive(self.root, value)

    def _delete_recursive(self, current_node, value):
        if current_node is None:
            return current_node

        # Find the node to delete
        if value < current_node.value:
            current_node.left = self._delete_recursive(current_node.left, value)
        elif value > current_node.value:
            current_node.right = self._delete_recursive(current_node.right, value)
        else:
            # Node to delete found

            # Case 1: Node has no children (leaf node)
            if current_node.left is None and current_node.right is None:
                return None

            # Case 2: Node has only one child
            if current_node.left is None:
                return current_node.right
            elif current_node.right is None:
                return current_node.left

            # Case 3: Node has two children
            # Find the in-order successor (smallest in the right subtree)
            successor = self._find_min(current_node.right)
            current_node.value = successor.value
            # Delete the successor node
            current_node.right = self._delete_recursive(current_node.right, successor.value)

        return current_node
    #endregion
    
    def _find_min(self, node):
        # Find the smallest node in a subtree
        while node.left is not None:
            node = node.left
        return node
        
    #region print
    def print_in_order(self):
        print("Agac: ")
        self._print_in_order_recursive(self.root)
        print()

    def _print_in_order_recursive(self, current_node):
        if current_node:
            self._print_in_order_recursive(current_node.left)
            print(current_node.value, end=" ")
            self._print_in_order_recursive(current_node.right)
    #endregion
        
# BST örneği oluşturma
agac = BinarySearchTree()

# Ağaca düğümler ekleme
for i in range(random.randint(50,100)):
    agac.insert(random.randint(0,200))
agac.print_in_order()


print("Islemler: 1-Deger Ara, 2-Değer sil")
secim=int(input("İslem: "))
if secim==1: #Deger arama
    deger = int(input("Aranacak Deger: "))    
    if agac.search(deger):
        print("Değer bulundu:", deger)
    else:
        print("Değer bulunamadı.")
elif secim==2:
    deger = int(input("Silinecek Deger: "))
    agac.delete(deger)
    agac.print_in_order()

