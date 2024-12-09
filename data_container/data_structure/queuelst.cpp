#include "queuelst.h"
#include <mutex>

QueueLst::QueueLst(const QueueLst& src) {
    if (!src.IsEmpty()) {
        head_ = new Node{src.head_->val};
        Node* p_src = src.head_;
        Node* p_dst = head_;
        while (p_src->next) {
            p_dst->next = new Node{p_src->next->val};
            p_src = p_src->next;
            p_dst = p_dst->next;
        }
        tail_ = p_dst;
    }
}

QueueLst::QueueLst(QueueLst&& src) noexcept
    : head_(src.head_), tail_(src.tail_) {
    src.head_ = nullptr;
    src.tail_ = nullptr;
}

QueueLst& QueueLst::operator=(const QueueLst& src) {
    if (this != &src) {
        if (src.IsEmpty()) {
            Clear();
        } else {
            QueueLst copy(src);
            std::swap(head_, copy.head_);
            std::swap(tail_, copy.tail_);
        }
    }
    return *this;
}

QueueLst& QueueLst::operator=(QueueLst&& src) noexcept {
    if (this != &src) {
        std::swap(head_, src.head_);
        std::swap(tail_, src.tail_);
    }
    return *this;
}

bool QueueLst::IsEmpty() const noexcept {
    return nullptr == head_;
}

void QueueLst::Pop() noexcept {
    sum_ -= Top();
    if (!IsEmpty()) {
        Node* deleted = head_;
        head_ = head_->next;
        delete deleted;
    }
    if (IsEmpty()) {
        tail_ = nullptr;
    }
    size_--;
    average_number = sum_ / size_;
}

void QueueLst::Push(const double& val) {
    if (size_ == maxsize_){
        Pop();
    }
    if (IsEmpty()) {
        tail_ = new Node{val};
        head_ = tail_;
    } else {
        tail_->next = new Node{val};
        tail_ = tail_->next;
    }
    size_++;
    sum_ += val;
    average_number = sum_ / size_;
}

double& QueueLst::Top() & {
    if (IsEmpty()) {
        throw std::logic_error("QueueLst - try get top form empty queue.");
    }
    return head_->val;
}

const double& QueueLst::Top() const & {
    if (IsEmpty()) {
        throw std::logic_error("QueueLst - try get top form empty queue.");
    }
    return head_->val;
}

double& QueueLst::Tail()&{
    return tail_->val;
}

void QueueLst::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}

double QueueLst::ReturnAverage() {
    return average_number;
}

//    std::lock_guard<std::mutex> lock(mutex_);
