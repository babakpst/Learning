//============================================================================
// Name        : GMockTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using ::testing::_;
using ::testing::Return;

class QueueInterface {
public:
	virtual ~QueueInterface(){;}
	virtual void enqueue( int data ) = 0;
	virtual int dequeue() = 0;
};

class MockQueue : public QueueInterface {
public:
	MOCK_METHOD0(dequeue, int());
	MOCK_METHOD1(enqueue, void(int data));
};

class DataHolder {
public:
	DataHolder(QueueInterface *queue):queue(queue){;}
	void addData( int data ){
		queue->enqueue(data);
	}

	int getData(){
		return queue->dequeue();
	}
protected:
	QueueInterface *queue;
};

TEST(GMockTests, CanAddData){
	MockQueue myMockObj;
	DataHolder dh(&myMockObj);

	EXPECT_CALL(myMockObj, enqueue(_));
	dh.addData(1);
}

TEST(GMockTests, CanAddAndGetData){
	MockQueue myMockObj;
	DataHolder dh(&myMockObj);
	EXPECT_CALL(myMockObj, enqueue(1));
	EXPECT_CALL(myMockObj, dequeue()).WillOnce(Return(1));
	dh.addData(1);
	int data = dh.getData();
	ASSERT_EQ(1, data);
}
