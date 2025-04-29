// #include <log4cpp/Category.hh>
// #include <log4cpp/OstreamAppender.hh>
// #include <log4cpp/BasicLayout.hh>
// #include <log4cpp/Priority.hh>

// int main()
// {
//     log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("console", &std::cout);
//     osAppender->setLayout(new log4cpp::BasicLayout());

//     log4cpp::Category& root = log4cpp::Category::getRoot();
//     root.setPriority(log4cpp::Priority::DEBUG);
//     root.addAppender(osAppender);

//     root.debug("this is a debug message");
//     root.info("this is an info message");
//     root.warn("this is a warning");
//     root.error("this is an error");

//     log4cpp::Category::shutdown();
//     return 0;
// }


// #include <log4cpp/Category.hh>
// #include <log4cpp/OstreamAppender.hh>
// #include <log4cpp/BasicLayout.hh>
// #include <log4cpp/Priority.hh>
// #include <log4cpp/FileAppender.hh>

// int main()
// {
//     log4cpp::Appender* fileAppender = new log4cpp::FileAppender("fileAppender", "mylog.log");
//     fileAppender->setLayout(new log4cpp::BasicLayout());

//     log4cpp::Category& root = log4cpp::Category::getRoot();
//     root.setPriority(log4cpp::Priority::DEBUG);
//     root.addAppender(fileAppender);

//     root.debug("this is a debug message");
//     root.info("this is an info message");
//     root.warn("this is a warning");
//     root.error("this is an error");

//     log4cpp::Category::shutdown();
//     return 0;
// }

// #include <log4cpp/Category.hh>
// #include <log4cpp/OstreamAppender.hh>
// #include <log4cpp/BasicLayout.hh>
// #include <log4cpp/Priority.hh>
// #include <log4cpp/FileAppender.hh>
// #include <log4cpp/PatternLayout.hh>

// int main()
// {
//     log4cpp::PatternLayout* layout = new log4cpp::PatternLayout();
//     layout->setConversionPattern("%d [%p] %c: %m%n");  // 时间 [优先级] 类别: 消息

//     log4cpp::Appender* fileAppender = new log4cpp::FileAppender("fileAppender", "mylog.log");
//     fileAppender->setLayout(layout);    

//     log4cpp::Category& root = log4cpp::Category::getRoot();
//     root.setPriority(log4cpp::Priority::DEBUG);
//     root.addAppender(fileAppender);

//     root.debug("this is a debug message");
//     root.info("this is an info message");
//     root.warn("this is a warning");
//     root.error("this is an error");

//     log4cpp::Category::shutdown();
//     return 0;
// }

// #include <log4cpp/Category.hh>
// #include <log4cpp/OstreamAppender.hh>
// #include <log4cpp/BasicLayout.hh>
// #include <log4cpp/Priority.hh>

// int main() {
//     // 创建一个输出到标准输出的 Appender
//     log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("console", &std::cout);
//     osAppender->setLayout(new log4cpp::BasicLayout());

//     // 获取根 Category，并设置优先级
//     log4cpp::Category& root = log4cpp::Category::getRoot();
//     root.setPriority(log4cpp::Priority::DEBUG);
//     root.addAppender(osAppender);

//     // 记录日志
//     root.debug("This is a debug message");
//     root.info("This is an info message");
//     root.warn("This is a warning");
//     root.error("This is an error");

//     // 清理
//     log4cpp::Category::shutdown();
//     return 0;
// }
