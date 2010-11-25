<div class="wrapper">
	<div class="nav">
		<a href="#">view store </a>
		<a href="#">view cart </a>
		<a href="#">clear cart </a>
	</div>
	<table class="products">
		<tr>
<?php foreach(get_xml_catalog() as $product){ ?>
			<td><h2><?php print "$product->title"?></h2>
			<div class="nav">
			<img src="<?php print "$product->img"?>" height="100" width="80"/>
			<span>
			    <?php print "$product->description"?>
			</span>
			</div>
			<div class="price">
						<?php print "$product->price"?>
			</div>
			<div class="addtocart">
				<a href="#">add to cart</a>
			</div>
			</td>
<?php
	}
?>
		</tr>
	</table>
</div>