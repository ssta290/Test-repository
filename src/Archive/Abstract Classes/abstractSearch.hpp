template <typename T>
class searchStrategy {
 public:
  virtual ~SearchStrategy() = default;  // Always give a vitual destructor
  virtual T* FindEntry(const int key) = 0;
};