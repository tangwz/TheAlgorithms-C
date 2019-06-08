void run_all_tests() {
    test_empty();
    test_all();
}

void test_empty() {
    Queue queue = queue_create();
    assert(is_empty(queue));
}

void test_all() {
    Queue q = queue_create();

    enqueue(q, 100);
    assert(is_empty(q) == false);
    assert(dequeue(q) == 100);
    enqueue(q, 200);
    enqueue(q, 300);
    enqueue(q, 400);
    assert(dequeue(q) == 200);
    assert(dequeue(q) == 300);
    assert(dequeue(q) == 400);

    assert(is_empty(q));
}