using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace MonsterCardsWebApp.Models
{
	public class MonsterCard
	{
		public string Name { get; set; }
		public string Slogan { get; set; }
		public int EyeCount { get; set; }

		public string Description { get; set; }
		public decimal OriginalPrice { get; set; }
		public decimal SellPrice { get; set; }
		public string ImageUri { get; set; }
		public string ShortDescription { get; set; }

	}
}
