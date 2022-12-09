<?php
//sleep(3);
include('db.php');
$html="";
$click_count=$_POST['click_count']-2;
$res=mysqli_query($con,"select * from comments limit $click_count,2");
while($row=mysqli_fetch_assoc($res)){
$html.='<div class="row comment">
	<div class="head">
	   <small><strong class="user">'.$row['name'].'</strong> </small>
	</div>
	<p>'.$row['comment'].'</p>
 </div>';
} 

$click_count=$click_count+2;
if(mysqli_num_rows(mysqli_query($con,"select * from comments limit $click_count,1"))>0){
	$status='yes';
}else{
	$status='no';
}

echo json_encode(['status'=>$status,'html'=>$html]);
?>