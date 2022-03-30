    function getData() {
        var data = localStorage.getItem('todolist');//获取本地数据
        if (data != null) {              //判断本地存储中是否有数据
            return JSON.parse(data);     //有的话返回
        } else {
            return [];                   //没有的话返回[]
        }
    }
//将数据保存到本地存储
    function saveDate(data) {
        localStorage.setItem('todolist', JSON.stringify(data));
    }
