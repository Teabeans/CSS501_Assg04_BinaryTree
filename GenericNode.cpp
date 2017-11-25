template<class T>
struct GenericNode {
   T nodeData;
   bool isDeleted;
   GenericNode<T>* leftPtr;
   GenericNode<T>* rightPtr;

   GenericNode() {
      isDeleted = 1;
      leftPtr = nullptr;
      rightPtr = nullptr;
   }

   GenericNode(T someData) {
      nodeData = someData;
      isDeleted = 0;
      leftPtr = nullptr;
      rightPtr = nullptr;
   }
};
