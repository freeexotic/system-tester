#pragma once

#include <stdexcept>
#include <algorithm>
#include <mutex>

class QueueLst final {
public:
    QueueLst() = default;

    QueueLst(const QueueLst& qul);

    QueueLst(QueueLst&& qul) noexcept;

    ~QueueLst() = default;

    QueueLst& operator=(const QueueLst& qul);

    QueueLst& operator=(QueueLst&& qul) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const double& data);

    [[nodiscard]] double& Top() &;

    [[nodiscard]] double& Tail() &;

    [[nodiscard]] const double& Top() const &;

    void Clear() noexcept;

    double ReturnAverage ();

private:
    struct Node {
        double val;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    unsigned int size_ = 0;
    unsigned int maxsize_ = 200;
    double average_number;
    long double sum_ = 0;

    mutable std::mutex mutex_;
};

