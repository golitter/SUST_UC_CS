
let sumObject = localStorage.length;

let form_verify = layui.use('form', function () {
    var form = layui.form;

    form.verify({
        self_email: [
            /^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$/
            , 'Please enter the correct email address!'
        ],
        self_phone: [
            /^[1][3-9][0-9]{9}$/
            , 'The format of the phone number is wrong!'
        ]
    });
    
    form.on('submit(getInfo)', function (data) {
        layer.msg('Successful submission');

        let _objName = `key${sumObject++}`;
        localStorage.setItem(_objName, JSON.stringify(data.field));
        console.log(localStorage);
        // return false;
    });
});

