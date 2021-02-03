const app = document.getElementById('root');

//const logo = document.createElement('img');
//logo.src = 'logo.png';

const container = document.createElement('div');
container.setAttribute('class', 'container');

//app.appendChild(logo);
app.appendChild(container);

var username = prompt("Please enter your osu name", "");
//if (ID!= null) {
//    document.getElementById("ID").value = ID;
//}

let request = new XMLHttpRequest();
let osuAPIkey = '66e4541725e87c2ef4559e7929d68b5c319719d3';
//let ID = '9676089';
request.open('GET', 'https://osu.ppy.sh/api/get_user?u=' + username + '&k=' + osuAPIkey);
request.onload = function () {
  // Begin accessing JSON data here
  //var url = 'https://osu.ppy.sh/api/get_user?' + 'k=' + osuAPIkey + '&u=' + '9676089';
  //var response =  UrlFetchApp.fetch(url);
  let data = JSON.parse(request.response);
  if (request.status >= 200 && request.status < 400) {

    //const h1 = document.createElement('h1');
    //h1.textContent = data[0].user_id;
    //app.appendChild(h1);
    document.getElementById("User ID").innerHTML = "User ID: " + data[0].user_id + "\n";
    document.getElementById("Osu Username").innerHTML = "Osu username: " + data[0].username + "\n";
    document.getElementById("PP").innerHTML = "PP: " + data[0].pp_raw + "\n";
    document.getElementById("Rank").innerHTML = "Rank: #" + data[0].pp_rank + "\n";
    document.getElementById("Country").innerHTML = "Country: " + data[0].country + "\n";
r
    //h1.textContent = data[0].country;
    //app.appendChild(h1);
    
  } else {
    const errorMessage = document.createElement('marquee');
    errorMessage.textContent = `Gah, it's not working!`;
    app.appendChild(errorMessage);
  }
}

request.send();