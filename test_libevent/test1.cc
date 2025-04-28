#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>
#include <event2/util.h>
#include <event2/listener.h>

void request_handler(struct evhttp_request *req, void *arg)
{
    // 处理请求
    const char *uri = evhttp_request_get_uri(req);
    printf("Got request for %s\n", uri);
    
    // 创建响应缓冲区
    struct evbuffer *buf = evbuffer_new();
    evbuffer_add_printf(buf, "Hello, World! You requested %s", uri);
    
    // 发送响应
    evhttp_send_reply(req, HTTP_OK, "OK", buf);
    evbuffer_free(buf);
}

int main()
{
    struct event_base *base = event_base_new();
    struct evhttp *http = evhttp_new(base);
    
    // 绑定到端口 8080
    evhttp_bind_socket(http, "0.0.0.0", 8080);
    
    // 设置通用请求处理器
    evhttp_set_gencb(http, request_handler, NULL);
    
    // 也可以设置特定URI的处理器
    // evhttp_set_cb(http, "/api", api_handler, NULL);
    
    event_base_dispatch(base);
    
    // 清理
    evhttp_free(http);
    event_base_free(base);
    
    return 0;
}