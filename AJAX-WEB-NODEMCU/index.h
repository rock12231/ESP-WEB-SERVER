const char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style type="text/css">
.button {
  background-color: #4CAF50; /* Green */
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
}
.divsize{
  width: 600px;
  height: 300px;
  background-color: #8ae18d;
}
</style>
<script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
<body style="background-color: #f9e79f ">
<center>
<div>
<h1>AJAX BASED ESP8266 WEBSERVER</h1>
  <button class="button" onclick="send(1)">LED ON</button>
  <button class="button" onclick="send(0)">LED OFF</button><BR>
</div>
 <br>
<div><h2>
  Temp(C): <span id="adc_val">0</span><br><br>
  LED State: <span id="state">NA</span>
</h2>
</div>
<br>
<br>
Input: <input type="submit" value="Click" onclick="clickme()">
<br>
<br>
<div class="divsize">
<canvas id="myChart"></canvas>
</div>
</center>
<script>
function send(led_sts) 
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "led_set?state="+led_sts, true);
  xhttp.send();
}
setInterval(function() 
{
  getData();
}, 2000); 
var a = [0, 0, 0, 0, 0, 0];
function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("adc_val").innerHTML = this.responseText;
      console.log(a);
      a.unshift(this.responseText);
      console.log(a);
      a.pop();
      console.log(a);
      myChart.data.datasets[0].data = a;
      myChart.update();
    }
  };
  xhttp.open("GET", "adcread", true);
  xhttp.send();
}
</script>
<script>
  function clickme(){
    console.log(a);
    a.unshift(15);
    console.log(a);
    a.pop();
    console.log(a);
    myChart.data.datasets[0].data = a;
    myChart.update();
  }
</script>
<script>
const ctx = document.getElementById('myChart').getContext('2d');
const myChart = new Chart(ctx, {
    type: 'line',
    data: {
        labels: ['Red', 'Blue', 'Yellow', 'Green', 'Purple', 'Orange'],
        datasets: [{
            label: '#Temperature',
            data: [12, 19, 3, 5, 2, 3],
            backgroundColor: [
                'rgba(255, 99, 132, 0.2)',
                'rgba(54, 162, 235, 0.2)',
                'rgba(255, 206, 86, 0.2)',
                'rgba(75, 192, 192, 0.2)',
                'rgba(153, 102, 255, 0.2)',
                'rgba(255, 159, 64, 0.2)'
            ],
            borderColor: [
                'rgba(255, 99, 132, 1)',
                'rgba(54, 162, 235, 1)',
                'rgba(255, 206, 86, 1)',
                'rgba(75, 192, 192, 1)',
                'rgba(153, 102, 255, 1)',
                'rgba(255, 159, 64, 1)'
            ],
            borderWidth: 3
        }]
    },
    options: {
        scales: {
            y: {
                beginAtZero: true
            }
        }
    }
});
</script>
</body>
</html>
)=====";