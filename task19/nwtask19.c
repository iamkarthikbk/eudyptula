#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/textsearch.h>

#define LFID "a24a6bdd6a14"
#define LFID_LENGTH 13

MODULE_LICENSE("GPL");
MODULE_AUTHOR("a24a6bdd6a14 B K Karthik");
MODULE_DESCRIPTION("[NETFILTER] Task 19 of The Eudyptula Challenge");

static struct ts_config *conf;

static unsigned int my_hook(const struct nf_hook_ops *ops,
				struct sk_buff *skb,
				int (*okfn)(struct sk_buff *))
{
	int position;
	struct ts_state state;

	memset(&state, 0, sizeof(struct ts_state));

	for (position = skb_find_text(skb, 0, INT_MAX, conf);
			position != UINT_MAX;
			position = textsearch_next(conf, &state))
		pr_debug(LFID " at %d\n", position);
	return NF_ACCEPT;
}

static struct nf_hook_ops my_hooks = {
	.hook = my_hook,
	.hooknum = NF_INET_LOCAL_IN,
	.pf = NFPROTO_IPV4,
	.priority = NF_IP_PRI_FIRST
};

static int __init my_init(void)
{
	pr_debug("Registering hook\n");

	conf = textsearch_prepare("kmp", LFID, 12, GFP_KERNEL, TS_AUTOLOAD);
	if (IS_ERR(conf))
		return PTR_ERR(conf);

	return nf_register_net_hook(&init_net, my_hooks);
}

static void __exit my_exit(void)
{
	pr_debug("Unregistering hook\n");
	textsearch_destroy(conf);
	nf_unregister_net_hook(&init_net, my_hooks);
}

module_init(my_init);
module_exit(my_exit);


/* https://www.linuxjournal.com/article/7184 was used as a reference.
 * https://medium.com/bugbountywriteup/linux-kernel-communication-part-1-netfilter-hooks-15c07a5a5c4e was used as a reference.
 * https://wiki.aalto.fi/download/attachments/70789072/netfilter-paper-final.pdf?version=1&modificationDate=1355436336000&api=v2&download=true was used as a reference.
 * https://devarea.com/introduction-to-network-filters-linux/#.XxZyoGMza00 was used as a reference.
 */
