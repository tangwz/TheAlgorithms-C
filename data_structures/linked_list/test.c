void run_all_tests() {
    test_list_size();
    test_list_empty();
    test_list_push_front();
    test_list_push_back();
    test_list_front();
    test_list_back();
    test_list_pop_front();
    test_list_pop_back();
    test_list_find();
    test_list_value_at();
    test_list_erase();
    test_list_reverse();
}

void test_list_size() {
    int size = 0;

    Linked_List tester = list_init();
    size = list_size(tester);
    assert(size == 0);

    list_push_front(tester, 1);
    assert(list_size(tester) == 1);

    list_free(tester);
}

void test_list_empty() {
    Linked_List tester = list_init();
    assert(list_empty(tester) == 1);

    list_push_front(tester, 1);
    assert(list_empty(tester) == 0);

    list_push_front(tester, 2);
    assert(list_empty(tester) == 0);

    list_free(tester);
}

void test_list_push_front() {
    Linked_List tester = list_init();
    assert(list_size(tester) == 0);

    list_push_front(tester, 1);
    assert(list_size(tester) == 1);

    list_print(tester);

    list_push_front(tester, 2);
    list_push_front(tester, 3);
    assert(list_size(tester) == 3);

    list_print(tester);

    list_free(tester);
}

void test_list_push_back() {
    Linked_List tester = list_init();
    assert(list_size(tester) == 0);

    list_push_back(tester, 1);
    assert(list_size(tester) == 1);

    list_print(tester);

    list_push_back(tester, 2);
    list_push_back(tester, 3);
    assert(list_size(tester) == 3);

    list_print(tester);

    list_free(tester);
}

void test_list_front() {
    Linked_List tester = list_init();
    list_push_front(tester, 1);
    assert(list_front(tester) == 1);

    list_push_front(tester, 2);
    assert(list_front(tester) == 2);

    list_free(tester);
}

void test_list_back() {
    Linked_List tester = list_init();
    list_push_back(tester, 1);
    assert(list_back(tester) == 1);

    list_push_back(tester, 2);
    assert(list_back(tester) == 2);

    list_free(tester);
}

void test_list_pop_front() {
    Linked_List tester = list_init();
    list_push_front(tester, 1);
    list_push_front(tester, 2);
    list_print(tester);
    assert(list_pop_front(tester) == 2);
    list_print(tester);
    assert(list_pop_front(tester) == 1);

    list_free(tester);
}

void test_list_pop_back() {
    Linked_List tester = list_init();
    list_push_back(tester, 1);
    list_push_back(tester, 2);
    assert(list_pop_back(tester) == 2);
    assert(list_pop_back(tester) == 1);

    list_free(tester);
}

void test_list_find() {
    Linked_List tester = list_init();
    list_push_back(tester, 1);
    list_push_back(tester, 2);

    assert(list_find(tester, 1) == 0);
    assert(list_find(tester, 2) == 1);

    list_free(tester);
}

void test_list_value_at() {
    Linked_List tester = list_init();

    list_push_back(tester, 1);
    list_push_back(tester, 2);
    list_push_back(tester, 3);

    assert(list_value_at(tester, 0) == 1);
    assert(list_value_at(tester, 1) == 2);
    assert(list_value_at(tester, 2) == 3);

    list_free(tester);
}

void test_list_erase() {
    Linked_List tester = list_init();
    list_push_front(tester, 5);
    list_erase(tester, 0);

    assert(list_size(tester) == 0);

    list_push_back(tester, 1);
    list_push_back(tester, 2);

    list_erase(tester, 0);
    assert(list_find(tester, 2) == 0);

    list_push_back(tester, 3);
    list_erase(tester, 1);

    assert(list_find(tester, 2) == 0);

    list_push_back(tester, 3);
    list_push_back(tester, 4);
    list_print(tester);
    list_erase(tester, 2);
    list_print(tester);
    assert(list_find(tester, 3) == 1);

    list_free(tester);
}

void test_list_reverse() {
    Linked_List tester = list_init();

    list_push_back(tester, 1);
    list_push_back(tester, 2);
    list_push_back(tester, 3);
    list_push_back(tester, 4);
    list_push_back(tester, 5);

    list_reverse(tester);
    list_print(tester);

    assert(list_value_at(tester, 0) == 5);
    assert(list_value_at(tester, 1) == 4);
    assert(list_value_at(tester, 2) == 3);
    assert(list_value_at(tester, 3) == 2);
    assert(list_value_at(tester, 4) == 1);
    list_free(tester);
}