
let _nowLength = $("tr").length -1;

let addTable = (number) => {
    let dataset = localStorage.getItem(localStorage.key(number));
    dataset = JSON.parse(dataset);
    let table = document.querySelector(".watch_table");
    table.innerHTML += "\n<tr>\n" +
    "<td>" + dataset.cmpname + "</td>\n" +
    "<td>" + dataset.email + "</td>\n" +
    "<td>" + dataset.phone + "</td>\n" +
    "<td>" + dataset.other_info + "</td>\n" +
    "</tr>\n";
}

let forEachLocalStorage = () => {
    for(; _nowLength < localStorage.length; ++_nowLength) {
        addTable(_nowLength);
    } 
}

let changeStart = () => {
    let lis = document.querySelectorAll('li')
    let page01 = document.getElementById('page01')
    let page02 = document.getElementById('page02')
    let page03 = document.getElementById('page03')

    for (let i = 0; i < lis.length; i++) {
        lis[i].onclick = function (event) {
            if (event.target.classList.contains('first')) {
                changePage();
                page01.style.display = 'block';
            } else if (event.target.classList.contains('second')) {
                changePage();
                page02.style.display = 'block';
            } else if (event.target.classList.contains('third')) {
                changePage();
                page03.style.display = 'block';
                forEachLocalStorage();
            }
        }
    }
}

let changePage = () => {
    document.querySelectorAll('.page').forEach(el => {
        el.style.display = 'none'
    });
}

changeStart();