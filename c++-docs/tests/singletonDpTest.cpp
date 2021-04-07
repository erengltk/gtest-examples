#include"singletonDp.cpp"
//#include"Desktop/proj2/c++-docs/src/singletonDp.cpp"
TEST(RecordFinderTests,SingletonTotalPopulationTest)
    {
        SingletonRecordFinder rf;
        vector<string> names{"Istanbul","Seul"};
        int totalPop=rf.return_total_population(names);
        EXPECT_EQ(234223+23424,totalPop);
    }
    

    int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }