const char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<script type="text/javascript">

</script>
<style>
.divsize {
    width: 600px;
    height: 300px;
    background-color: rgba(255,0,0,0.1);
    border-radius: 5px;
}
h1,h2{
  color:#fff;
}
html{
  height:100%;
}
body{
  height:100hv;
}
</style>
<script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
<body style="background-image: linear-gradient(to right top, #051937, #004d7a, #008793, #00bf72, #a8eb12);">
<center>
<div>
  <h1>Live temperature with Line Graph</h1>
</div>
 <br>
<div><h2>
  Temp(C): <span id="adc_val">0</span><br><br>
</h2>
</div>
<br>
<br>
<div class="divsize">
<canvas id="myChart"></canvas>
</div>
</center>
</body>
<script>
setInterval(function(){
  getData();
}, 2000); 
var a = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
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
Chart.defaults.color = "#fff";
const ctx = document.getElementById('myChart').getContext('2d');
const myChart = new Chart(ctx, {
    type: 'line',
    data: {
        labels: ['1sec', '2sec', '3sec', '4sec', '5sec', '6sec','7sec', '8sec', '9sec', '10sec', '11sec', '12sec','13sec', '14sec', '15sec', '16sec', '17sec', '18sec','19sec', '20sec'],
        datasets: [{
            label: '#Temperature',
            data: [27, 27, 27, 27, 27, 27,27, 27, 27, 27, 27, 27,27, 27, 27, 27, 27, 27, 27, 27],
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
</html>
)=====";